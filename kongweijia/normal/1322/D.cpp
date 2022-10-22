#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=(a);i<=(n);i++)
#define per(i,a,n) for(int i=(n);i>=(a);i--)
#define infty 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define xx first
#define yy second
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
//head

const int maxn=4000;

ll dp[maxn+5][maxn+5],tmp[maxn+5],pre[maxn+5];
int s[maxn+5],c[maxn+5],l[maxn+5];
int w[maxn+5][maxn/2+5][12];


int main()
{
	int n,m; scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%d",&l[i]);
	rep(i,1,n) scanf("%d",&s[i]);
	rep(i,1,n+m) scanf("%d",&c[i]);
	per(l,1,n+m) rep(j,1,n) rep(s,1,11)
	{
		w[l][j][s]+=j*c[l]+w[l+1][j/2][s-1];
	}
	rep(i,0,n+m) rep(j,0,n) dp[i][j]=-(1ll<<60);
	dp[0][1]=0;
	per(rt,1,n)
	{
		int L=l[rt];
		rep(j,0,n) tmp[j]=-(1ll<<60);
		rep(i,max(0,L-11),L)
		{
			per(j,1,n)
			{
				tmp[(j>>L-i)+1]=max(tmp[(j>>L-i)+1],dp[i][j]+w[i][j][L-i]-s[rt]);
			}
		}
		rep(i,0,L) tmp[1]=max(tmp[1],pre[i]-s[rt]);
		rep(j,0,n)
		{
			int tt=j,c=0;
			while(tt) c++,tt/=2;
			if(tmp[j]>dp[L][j])
			{
				pre[L+c]=max(pre[L+c],tmp[j]+w[L][j][c]);
				dp[L][j]=tmp[j];
			}
		}
	}
	ll ans=0;
	rep(i,1,n+m) rep(j,1,n) if(dp[i][j]!=-(1ll<<60)) 
	{
		int tt=j,c=0;
		while(tt) c++,tt/=2;
		ans=max(ans,dp[i][j]+w[i][j][c]);
	}
	printf("%I64d\n",ans);
	return 0;
}