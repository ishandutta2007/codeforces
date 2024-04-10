#include <stdio.h>
#include <string.h>

char x[200010];
int count[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		for(int i=1;i<=a;i++) count[i] = x[i]-'0';
		for(int i=1;i<=a;i++) count[i] += count[i-1];
		
		int ans = 0;
		for(int i=1;i<=20;i++)
		{
			for(int j=1;j+i-1<=a;j++)
			{
				if(x[j]=='0') continue;
				int S = 0;
				for(int k=j;k<=j+i-1;k++)
				{
					S*=2;
					S+=(x[k]-'0');
				}
				if(S>=i)
				{
					int R = j-1;
					int L = R-(S-i)+1;
					if(L>=1&&count[R]-count[L-1]==0)
					{
						//printf("%d %d %d %d!!\n",i,S,L,R);
						ans++;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
}