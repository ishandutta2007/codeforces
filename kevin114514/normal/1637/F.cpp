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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
vector<int> G[200200];
ll h[200200];
pair<ll,ll> dfs(int u,int fa)
{
	ll cost=0;
	multiset<ll> st;
	for(auto v:G[u]) if(v!=fa)
	{
		pair<ll,ll> x=dfs(v,u);
		cost+=x.first;
		st.insert(-x.second);
	}
	if(!fa)
	{
		st.insert(0);
		cost+=h[u]+*st.begin();
		st.erase(st.begin());
		cost+=h[u]+*st.begin();
		return mp(cost,-1);
	}
	else
	{
		st.insert(0);
		ll x=-(*st.begin());
		cost+=max(0ll,h[u]-x);
		return mp(cost,max(h[u],x));
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	int mx=*max_element(h+1,h+n+1);
	for(int i=1;i<=n;i++)
		if(h[i]==mx)
		{
			cout<<dfs(i,0).first<<endl;
			return 0;
		}
	return 0;
}