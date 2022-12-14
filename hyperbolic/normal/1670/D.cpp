#include <stdio.h>
#define gap 5

int sqrt(int k)
{
	if(k==0) return 0;
	if(k==1) return 1;
	
	int min = 0, max = k;
	int ans = k;
	while(min<=max)
	{
		int h = (min+max)/2;
		if((long long int)h*h<=k)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	return ans;
}


int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		int b = sqrt((a+5)/6);
		int ans = 12345678;
		for(int i=b-gap;i<=b+gap;i++)
		{
			for(int j=i;j<=b+gap;j++)
			{
				if(i>=1&&j>=1)
				{
					int t = a-2*i*j;
					if(t<=0)
					{
						ans = ans<i+j?ans:i+j;
						continue;
					}
					int s;
					if(t%(4*i)==0) s = t/(4*i);
					else s = t/(4*i)+1;
					//if(i+j+s==83) printf("%d : %d %d %d!!\n",b,i,j,s);
					ans = ans<i+j+s?ans:i+j+s;
				}
			}
		}
		printf("%d\n",ans);
	}
}