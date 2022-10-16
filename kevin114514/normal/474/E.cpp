#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define int long long
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
pii segtree[100100<<2];
int l[100100<<2],r[100100<<2];
void pushup(int u)
{
	if(l[u]!=r[u])
		segtree[u]=max(segtree[u<<1],segtree[u<<1|1]);
}
void update(int u,int p,int v)
{
	if(l[u]==r[u])
		segtree[u]=mp(v,p);
	else
	{
		int mid=(l[u]+r[u])>>1;
		if(p<=mid)
			update(u<<1,p,v);
		else	update(u<<1|1,p,v);
	}
	pushup(u);
}
pii query(int u,int ll,int rr)
{
	if(l[u]==ll&&r[u]==rr)
		return segtree[u];
	int mid=(l[u]+r[u])>>1;
	if(rr<=mid)
		return query(u<<1,ll,rr);
	else if(ll>mid)
		return query(u<<1|1,ll,rr);
	else	return max(query(u<<1,ll,mid),query(u<<1|1,mid+1,rr));
}
void reconstruct(int u,int ll,int rr)
{
	l[u]=ll;
	r[u]=rr;
	if(ll==rr)
		return ;
	reconstruct(u<<1,ll,(ll+rr)>>1);
	reconstruct(u<<1|1,((ll+rr)>>1)+1,rr);
}
int h[100100];
int hh[100100];
int pprev[100100];
int dp[100100];
int rec[100100];
signed main()
{
	vector<int> v;
	int n,d;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>h[i];
		hh[i]=h[i];
		v.pb(h[i]);
	}
	srt(v);
	for(int i=1;i<=n;i++)
	{
		h[i]=lower_bound(ALL(v),h[i])-v.begin();
//		cout<<h[i]<<" ";
	}
//	puts("");
	reconstruct(1,-1,n);
	for(int i=1;i<=n;i++)
	{
//		cout<<max((int)(upper_bound(ALL(v),hh[i]-d)-v.begin()-1),0ll)<<" "<<lower_bound(ALL(v),hh[i]+d)-v.begin()<<endl;
		pii p=max(query(1,-1,max((int)(upper_bound(ALL(v),hh[i]-d)-v.begin()-1),-1ll)),query(1,lower_bound(ALL(v),hh[i]+d)-v.begin(),n));
		//          <=h[i]-d 																	>=h[i]+d
//		cout<<"."<<p.first<<" "<<p.second<<endl;
		p.first+=1;
		dp[i]=p.first;
		pprev[i]=rec[p.second];
		update(1,h[i],p.first);
		rec[h[i]]=i;
	}
	int mx=0,p=0;
	for(int i=1;i<=n;i++)
		if(dp[i]>mx)
		{
			mx=dp[i];
			p=i;
		}
	vector<int> vv;
	for(int i=0;i<mx;i++)
	{
		vv.pb(p);
		p=pprev[p];
	}
	cout<<sz(vv)<<endl;
	for(int i=sz(vv)-1;i>=0;i--)
		cout<<vv[i]<<" ";
	return 0;
}