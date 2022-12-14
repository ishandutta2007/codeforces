#include <stdio.h>

int ans;
int check[110];
void func(int s, int min ,int max, int t)
{
	if(s>ans) return;
	max = t / (ans-s+1) < max? t / (ans-s+1) : max;
	
	int m = (1<<(ans-s+1))-1;
	min = (t-1)/m+1 > min? (t-1)/m+1 : min;
	
	if(min>max) printf("!");
	check[s] = min;
	func(s+1,min,2*min,t-min);
	
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		for(int i=1;;i++)
		{
			int b = (1<<(i+1))-1;
			if(b>=a)
			{
				ans = i;
				break;
			}
		}
		
		printf("%d\n",ans);
		func(1,1,2,a-1);
		check[0] = 1;
		for(int i=1;i<=ans;i++) printf("%d ",check[i]-check[i-1]);
		printf("\n");
		
	}
}