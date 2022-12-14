#include <stdio.h>
#define SIZE 10

int getQuery(int a, int b)
{
	printf("? %d %d\n",a,b);
	fflush(stdout);
	
	int c;
	scanf("%d",&c);
	return c;
}

int count[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		if(i==1)
		{
			for(int i=1;i<=a;i+=SIZE)
			{
				if(i+SIZE-1>a) count[i/SIZE] = (a-i+1)-getQuery(i,a);
				else count[i/SIZE] = SIZE-getQuery(i,i+SIZE-1);
			}
		}
		
		int sum = 0;
		for(int i=0;i<=a;i++)
		{
			if(sum+count[i]>=c)
			{
				int L = i*SIZE+1;
				int R = (i+1)*SIZE;
				if(R>a) R = a;
				
				int ans = R;
				while(L<=R)
				{
					int h = (L+R)/2;
					int t = h - getQuery(1,h);
					//printf("%d %d!!\n",h,t);
					if(t>=c)
					{
						ans = h;
						R = h-1;
					}
					else L = h+1;
				}
				count[i]--;
				printf("! %d\n",ans);
				fflush(stdout);
				goto u;
			}
			sum += count[i];
		}
		u:;
	}
}