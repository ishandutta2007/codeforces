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
#define pii pair<ll,ll>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
void die(string S){puts(S.c_str());exit(0);}
ll cnt[200200];
ll x[200200],p[200200];
ll mx[200200];
int ind[200200];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		vector<pair<pii,int>> vec;
		int n;
		ll m;
		scanf("%d%lld",&n,&m);
		for(int i=0;i<=n+1;i++)
			mx[i]=cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			ll xx,pp;
			scanf("%lld%lld",&xx,&pp);
			vec.pb(mp(mp(xx,pp),i));
		}
		srt(vec);
		for(int i=0;i<n;i++)
		{
			x[i+1]=vec[i].first.first;
			p[i+1]=vec[i].first.second;
			ind[vec[i].second]=i+1;
		}
		ll tot=0;
		multiset<ll> st;
		for(int i=1;i<=n;i++)
		{
			while(sz(st)&&*st.begin()<=x[i])
			{
				tot-=(*st.begin()-x[i-1]);
				st.erase(st.begin());
			}
			tot-=sz(st)*(x[i]-x[i-1]);
			tot+=p[i];
			cnt[i]+=tot;
			st.insert(x[i]+p[i]);
		}
		st.clear();
		x[n+1]=inf;
		tot=0;
		for(int i=n;i>=1;i--)
		{
			while(sz(st)&&-(*st.begin())>=x[i])
			{
				tot-=(*st.begin()+x[i+1]);
				st.erase(st.begin());
			}
			tot-=sz(st)*(x[i+1]-x[i]);
			st.insert(p[i]-x[i]);
			cnt[i]+=tot;
			tot+=p[i];
		}
		for(int i=1;i<=n;i++)
			cnt[i]=max(0ll,cnt[i]-m);
		ll tmp=-1ll*inf*inf;
		for(int i=1;i<=n;i++)
		{
			tmp+=x[i]-x[i-1];
			if(cnt[i])
				tmp=max(tmp,cnt[i]);
			mx[i]=max(mx[i],tmp);
		}
		tmp=-1ll*inf*inf;
		for(int i=n;i>=1;i--)
		{
			tmp+=x[i+1]-x[i];
			if(cnt[i])
				tmp=max(tmp,cnt[i]);
			mx[i]=max(mx[i],tmp);
		}
		for(int i=1;i<=n;i++)
			if(mx[ind[i]]<=p[ind[i]])
				putchar('1');
			else	putchar('0');
		puts("");
	}
	return 0;
}