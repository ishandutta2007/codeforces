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
map<int,int> cnt;
map<pii,bool> bl;
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		bl.clear();
		cnt.clear();
		int n,m;
		cin>>n>>m;
		vector<int> a,cc;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			a.pb(x);
			cnt[x]++;
		}
		while(m--)
		{
			int u,v;
			cin>>u>>v;
			bl[mp(u,v)]=bl[mp(v,u)]=1;
		}
		srt(a);
		a.resize(unique(ALL(a))-a.begin());
		for(auto x:a)
			cc.pb(cnt[x]);
		srt(cc);
		cc.resize(unique(ALL(cc))-cc.begin());
		vector<vector<int>> vs;
		vs.resize(sz(cc));
		for(auto x:a)
			vs[lb(cc,cnt[x])].pb(x);
		for(auto &v:vs)
			rsrt(v);
		ll ans=0;
		for(auto x:a)
			for(int i=0;i<sz(vs);i++)
				for(auto y:vs[i])
					if(!bl[mp(x,y)]&&x!=y)
					{
						ans=max(ans,(cnt[x]+cnt[y])*1ll*(x+y));
						break;
					}
		cout<<ans<<endl;
	}
	return 0;
}