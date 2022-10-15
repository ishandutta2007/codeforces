#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
//#define ll long long
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
#define int long long
void die(string S){puts(S.c_str());exit(0);}
int x[100100],a[100100],b[100100];
int psum[100100];
int segtree[400400];
void upd(int u,int l,int r,int p,int v)
{
	if(l==r)
	{
		segtree[u]=v;
		return ;
	}
	int mid=(l+r)/2;
	if(p<=mid)
		upd(u<<1,l,mid,p,v);
	else	upd((u<<1)|1,mid+1,r,p,v);
	segtree[u]=max(segtree[u<<1],segtree[(u<<1)|1]);
}
int query(int u,int l,int r,int ll,int rr)
{
	if(l==ll&&r==rr)
		return segtree[u];
	int mid=(l+r)/2;
	if(rr<=mid)
		return query(u<<1,l,mid,ll,rr);
	else if(ll>mid)
		return query((u<<1)|1,mid+1,r,ll,rr);
	else	return max(query(u<<1,l,mid,ll,mid),query((u<<1)|1,mid+1,r,mid+1,rr));
}
int segtree2[400400];
void upd2(int u,int l,int r,int p,int v)
{
	if(l==r)
	{
		segtree2[u]=v;
		return ;
	}
	int mid=(l+r)/2;
	if(p<=mid)
		upd2(u<<1,l,mid,p,v);
	else	upd2((u<<1)|1,mid+1,r,p,v);
	segtree2[u]=max(segtree2[u<<1],segtree2[(u<<1)|1]);
}
int query2(int u,int l,int r,int ll,int rr)
{
	if(l==ll&&r==rr)
		return segtree2[u];
	int mid=(l+r)/2;
	if(rr<=mid)
		return query2(u<<1,l,mid,ll,rr);
	else if(ll>mid)
		return query2((u<<1)|1,mid+1,r,ll,rr);
	else	return max(query2(u<<1,l,mid,ll,mid),query2((u<<1)|1,mid+1,r,mid+1,rr));
}
signed main()
{
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		a[i]+=a[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		b[i]+=b[i-1];
	}
	for(int i=1;i<=n;i++)
	{
		upd(1,1,n,i,a[i]-b[i]);
		upd2(1,1,n,i,b[i]-a[i]); 
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		if(a[r]-a[l-1]!=b[r]-b[l-1])
		{
			puts("-1");
			continue;
		}
		int delta=a[l-1]-b[l-1];
//		cout<<delta<<endl;
//		cout<<query(1,1,n,l,r)<<endl;
		if(query(1,1,n,l,r)>delta)
		{
			puts("-1");
			continue;
		}
		cout<<query2(1,1,n,l,r)+delta<<endl;
	}
	return 0;
}