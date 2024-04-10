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
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int p[220];
char s[220];
int f(string S)
{
	int n=sz(S);
	for(int j=1;j<=n;j++) if(n%j==0)
	{
		bool f=1;
		for(int k=0;k<n;k++)
			if(S[k]!=S[(k+j)%n])
				f=0;
		if(f)
			return j;
	}
}
bool vis[220];
string dfs(int u)
{
	if(vis[u])
		return "";
	vis[u]=1;
	return dfs(p[u])+s[u];
}
ll lcm(ll a,ll b)
{
	return a/__gcd(a,b)*b;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
			scanf("%d",p+i);
		memset(vis,0,sizeof(vis));
		ll x=1;
		for(int i=1;i<=n;i++) if(!vis[i])
			x=lcm(x,f(dfs(i)));
		cout<<x<<endl;
	}
	return 0;
}