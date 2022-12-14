#include <stdio.h>
#include <algorithm>
#include <vector>
#define MOD 1000000007

int x[5010];
int sum[5010][5010];
std::vector<int> V[5010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++) sum[x[i]][i] = 1;
	for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) sum[i][j] += sum[i][j-1];
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
	}
	for(int i=1;i<=a;i++) std::sort(V[i].begin(),V[i].end());
	
	long long int ans1 = 0, ans2 = 0;
	for(int j=0;j<=a;j++)
	{
		long long int S1 = 0, S2 = 1;
		//1~j / j+1~a
		for(int i=1;i<=a;i++)
		{
			int s1 = sum[i][j];
			int s2 = sum[i][a] - sum[i][j];
			
			int c1 = 0, c2 = 0;
			for(int k=0;k<V[i].size();k++) if(V[i][k]<=s1) c1 = k+1;
			for(int k=0;k<V[i].size();k++) if(V[i][k]<=s2) c2 = k+1;
			
			if(i==x[j+1])
			{
				if(c2==0) goto u;
				if(V[i][c2-1]==s2)
				{
					if(c1==0) S1++;
					else if(c1>=c2)
					{
						if(c1==1) S1++;
						else S1+=2,S2*=(c1-1),S2%=MOD;
					}
					else S1+=2,S2*=c1,S2%=MOD;
				}
				else goto u;
				continue;
			}
			if(c1>c2)
			{
				int C = c1;
				c1 = c2;
				c2 = C;
			}
			if(c1==0&&c2==0) continue;
			else if(c1==0) S1++, S2*=c2, S2%=MOD;
			else if(c2==1) S1++, S2*=2, S2%=MOD;
			else S1 += 2,S2 *= c1*(c2-1),S2%=MOD;
		}
		//printf("%d : %lld %lld!!\n",j,S1,S2);
		
		if(ans1<S1)
		{
			ans1 = S1;
			ans2 = S2;
		}
		else if(ans1==S1) ans2 += S2, ans2%=MOD;
		u:;
	}
	printf("%lld %lld\n",ans1,ans2);
}