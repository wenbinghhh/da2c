#include <stdio.h>
#define N 10
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
void order1(int *a,int n)/*冒泡排序法*/
{
	int i,f,j;
	for(i=0;i<n-1;i++)
        {
                f=0;
                for(j=0;j<n-i-1;j++)
                        {
                                if(a[j]>a[j+1])
                                        {
                                                /*
                                                t=a[j];
                                                a[j]=a[j+1];
                                                a[j+1]=t;
                                                */
                                                swap(a+j,a+j+1);
                                                f=1;
                                        }
                        }
                if(f==0)
                        {
                                break;
                        }
        }
}
void order2(int *a,int n )/*选择排序法*/
{
	int i,j,k;
	for(i=0;i<n-1;i++)
	{
		k=i;	
		for(j=i+1;j<n;j++)
			{
				if(a[j]<a[k])
					{
						k=j;
					}	
			}
		if(k!=i)
			{
				swap(a+i,a+k);
			}
	}
}
void order3(int *a,int n )/*插入排序法*/
{
	int i,j,m;
	for(i=0;i<n;i++)
	{
		m=a[i];	
		for(j=i-1;m<a[j]&&j>=0;j--)
			{
				a[j+1]=a[j];
			}
		a[j+1]=m;
	}
}
void order4(int *a,int n )/*两侧排序法*/
{
	int i,j,k1,k2;
	for(i=0;i<=n/2;i++)
	{
		k1=i;	
		for(j=i+1;j<n-i;j++)
			{
				if(a[j]>a[k1])
					{
						k1=j;
					}	
			}
		if(k1!=i)
			{
				swap(a+i,a+k1);
			}
		k2=n-i-1;
		for(j=i+1;j<n-i;j++)
                        {
                                if(a[j]>a[k2])
                                        {
                                                k2=j;
                                        }       
                        }
                if(k2!=n-i-1)
                        {
				swap(a+n-i-1,a+k2);
                        }
	}
}
void main()
{
	int i,a[N],j;
	printf("input %d number:\n",N);
	for(i=0;i<N;i++)
		{
			printf("%d:  ",i+1);
			scanf("%d",&a[i]);
			printf("\n");
		}
	order4(a,N);
	for(i=0;i<N;i++)
		{
			printf("%d\t",a[i]);
		}
	printf("\n");
}
