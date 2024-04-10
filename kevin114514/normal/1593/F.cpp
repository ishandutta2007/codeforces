#include<bits/stdc++.h>
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define srt(v) sort(ALL(v))
#define rALL(v) v.rbegin(),v.rend()
#define rsrt(v) sort(rALL(v))
#define mp make_pair
using namespace std;
bool dp[41][40][40][41];
pair<pair<int,int>,int> prv[41][40][40][41];
bool op[41][40][40][41];
int x[41];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int a,b;
		scanf("%d%d",&a,&b);
		char tmp=getchar();
		for(int i=0;i<n;i++)
		{
			char c=getchar();
			x[i]=c^48;
		}
		memset(dp,0,sizeof(dp));
		dp[0][0][0][0]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<a;j++)
				for(int k=0;k<b;k++)
					for(int l=0;l<=i;l++)
						if(dp[i][j][k][l])
						{
							dp[i+1][(j*10+x[i])%a][k][l+1]=1;
							prv[i+1][(j*10+x[i])%a][k][l+1]=mp(mp(j,k),l);
							op[i+1][(j*10+x[i])%a][k][l+1]=0;
							dp[i+1][j][(k*10+x[i])%b][l]=1;
							prv[i+1][j][(k*10+x[i])%b][l]=mp(mp(j,k),l);
							op[i+1][j][(k*10+x[i])%b][l]=1;
						}
		int ans=1e7,x=0;
		for(int i=1;i<n;i++)
			if(dp[n][0][0][i])
				if(abs(i-(n-i))<ans)
				{
					ans=abs(i-(n-i));
					x=i;
				}
		if(!x)
		{
			puts("-1");
			continue;
		}
		string S;
		a=0,b=0;
		int c=x;
		for(int i=n;i>=1;i--)
		{
			if(op[i][a][b][c])
				S+='B';
			else	S+='R';
			pair<pair<int,int>,int> p=prv[i][a][b][c];
			a=p.first.first;
			b=p.first.second;
			c=p.second;
		}
		reverse(ALL(S));
		puts(S.c_str());
	}
	return 0;
}