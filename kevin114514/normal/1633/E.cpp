#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define int ll
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
#define lb(v,x) (lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (upper_bound(ALL(v),x)-v.begin())
void die(string S){puts(S.c_str());exit(0);}
int n,m;
int u[330],v[330],w[330];
int fa[330];
int anc(int x)
{
	if(fa[x]==x)
		return x;
	return fa[x]=anc(fa[x]);
}
pii mst(int x)
{
	vector<pair<pii,pii>> vec;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++)
		vec.pb(mp(mp(abs(w[i]-x),w[i]<x),mp(u[i],v[i])));
	srt(vec);
	int ans=0;
	int cnt=0;
	for(auto e:vec)
	{
		if(anc(e.second.first)!=anc(e.second.second))
		{
			fa[anc(e.second.first)]=anc(e.second.second);
			ans+=e.first.first;
			cnt+=e.first.second*2;
			cnt--;
		}
	}
	return mp(ans-cnt*x,cnt);
}
int res[100100],midres[100100];
int cnt[100100],midcnt[100100];
signed main()
{
	cin>>n>>m;
	vector<int> vec;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
//		w[i]*=2;
		vec.pb(w[i]);
	}
	for(int i=1;i<=m;i++)
		for(int j=i+1;j<=m;j++)
			vec.pb((w[i]+w[j]+1)/2);
	srt(vec);
	vec.resize(unique(ALL(vec))-vec.begin());
	int tot=sz(vec);
	for(int i=1;i<=tot;i++)
	{
		pii p=mst(vec[i-1]);
		res[i]=p.first;
		cnt[i]=p.second;
//		cout<<vec[i-1]<<" "<<p.first<<" "<<p.second<<endl;
	}
	for(int i=1;i<tot;i++)
	{
		pii p=mst((vec[i-1]+vec[i])/2);
		midres[i]=p.first;
		midcnt[i]=p.second;
	}
	{
		pii p=mst(0);
		midres[0]=p.first;
		midcnt[0]=p.second;
//		cout<<" $0:"<<p.first<<" "<<p.second<<endl;
	}
	{
		pii p=mst(1e8);
		midres[tot]=p.first;
		midcnt[tot]=p.second;
	}
	int p,k,a,b,c;
	int ans=0;
	cin>>p>>k>>a>>b>>c;
	int lst=0;
	for(int i=1;i<=p;i++)
	{
		int l=ans;
		int x;
		cin>>x;
		int pos=ub(vec,x);
//		cout<<vec[pos]<<endl;
//		cout<<" $ "<<pos<<endl;
		ans^=((midres[pos]+x*midcnt[pos]));
//		cout<<x<<" "<<pos<<" "<<(ans^l)<<endl;
		lst=x;
	}
	for(int i=p+1;i<=k;i++)
	{
		int l=ans;
		int x=(lst*a+b)%c;
		int pos=ub(vec,x);
		ans^=((midres[pos]+x*midcnt[pos]));
//		cout<<(ans^l)<<endl;
		lst=x;
	}
	cout<<ans<<endl;
	return 0;
}