#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 500005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll v[maxn],n,m;
vector <int> mp[maxn];
ll h[maxn];
map <ll,ll> p;
set <ll> s;
const ll mod=998244353;

inline void H(int u)
{
	ll X=0;
	for(int i=0;i<mp[u].size();i++) X=(X*2333+mp[u][i])%mod;
	h[u]=X;
}

int main()
{
	int T=read();
	while(T--)
	{
		n=read(); m=read();
		for(int i=1;i<=n;i++) v[i]=read();
		for(int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			mp[v].push_back(u);
		}
		for(int i=1;i<=n;i++) sort(mp[i].begin(),mp[i].end()),H(i);
		for(int i=1;i<=n;i++)
		{
			if(h[i]==0) continue;
			else p[h[i]]+=v[i],s.insert(h[i]);
		}
		ll ans=p[*s.begin()];
		for(set <ll>::iterator it=s.begin();it!=s.end();it++) ans=__gcd(ans,p[*it]);
		printf("%lld\n",ans);
		
		for(int i=1;i<=n;i++) mp[i].clear(),h[i]=0; p.clear(); s.clear();
	}
	return 0;
}