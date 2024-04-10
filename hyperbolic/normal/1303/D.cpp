#include <stdio.h>
#include <stack>

std::stack<int> St;
int check[110],x[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		int b;
		scanf("%lld%d",&a,&b);
		for(int i=0;i<=60;i++) check[i] = x[i] = 0;
		//while(!St.empty()) St.pop();
		
		for(int i=1;i<=b;i++)
		{
			long long int c;
			scanf("%lld",&c);
			
			int count = 0;
			while(c>1) count++,c/=2;
			check[count]++;
		}
		
		int p = 0;
		while(a) x[p++] = a%2, a/=2;
		
		long long int ans = 0;
		int S = 0;
		for(int i=0;i<=60;i++)
		{
			S += check[i];
			if(x[i]==1)
			{
				if(S>0) S--;
				else
				{
					for(int j=i+1;j<=60;j++)
					{
						if(check[j]>0)
						{
							ans += (j-i);
							check[j]--;
							for(int k=i+1;k<=j-1;k++) check[k]++;
							goto v;
						}
					}
					printf("-1\n");
					goto u;
					
					v:;
				}
			}
			S/=2;
		}
		
		printf("%lld\n",ans);
		u:;
	}
}