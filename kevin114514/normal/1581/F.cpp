#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
void die(string S){puts(S.c_str());exit(0);}
ll dp[5005][5005];
int son[5005][2];
ll len[5005][2];
ll a[5005];
int build(int l,int r)
{
	if(l>r)
		return 0;
	int ind=0;
	ll x=1e18;
	for(int i=l;i<=r;i++)
		if(a[i]<x)
		{
			x=a[i];
			ind=i;
		}
	son[ind][0]=build(l,ind-1);
	son[ind][1]=build(ind+1,r);
//	cout<<l<<" "<<r<<" "<<ind<<endl;
//	cout<<son[ind][0]<<" "<<son[ind][1]<<endl;
	len[ind][0]=a[son[ind][0]]-a[ind];
	len[ind][1]=a[son[ind][1]]-a[ind];
	return ind;
}
int n,m;
int sz[5005];
void dfs(int u)
{
	if(!u)
		return ;
	sz[u]=1;
	for(int i=0;i<2;i++)
	{
		dfs(son[u][i]);
		for(int j=min(sz[u],m);j>=0;j--)
			for(int k=min(m,sz[son[u][i]]);k>=0;k--)
				dp[u][j+k]=max(dp[u][j+k],dp[son[u][i]][k]+dp[u][j]+1ll*k*(m-k)*len[u][i]);
		sz[u]+=sz[son[u][i]];
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",a+i);
	int root=build(1,n);
	dfs(root);
	printf("%lld",dp[root][m]);
	return 0;
}