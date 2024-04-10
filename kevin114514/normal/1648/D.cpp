#include<bits/stdc++.h>
#define ll long long
#define k1 (k<<1)
#define k2 (k<<1|1)
#define mid ((l+r)>>1)
#define pii pair<int,ll>
#define mp make_pair
using namespace std;
const int N=5e5+5;
const ll INF=1e18;
class Segment_Tree1{
	public:
		ll mx[N<<2];
		void init() {memset(mx,-0x3f,sizeof(mx));return;}
		void change(int k,int l,int r,int x,ll v)
		{
			if(l==r) {mx[k]=max(mx[k],v);return;}
			if(x<=mid) change(k1,l,mid,x,v);
			else change(k2,mid+1,r,x,v);
			mx[k]=max(mx[k1],mx[k2]);
			return;
		}
		ll query(int k,int l,int r,int x,int y)
		{
			x=max(x,l);y=min(r,y);
			if(x>y) return -INF;
			if(x<=l&&y>=r) return mx[k];
			return max(query(k1,l,mid,x,y),query(k2,mid+1,r,x,y));
		}
}T1;
class Segment_Tree2{
	public:
		struct node{
			ll lmx,rmx,mx;
			node(ll a=0,ll b=0,ll c=0) {lmx=a;rmx=b;mx=c;return;}
			node operator + (const node &x) const{
				return node(max(lmx,x.lmx),max(rmx,x.rmx),max(max(mx,x.mx),lmx+x.rmx));
			}
		}t[N<<2];
		void build(int k,int l,int r,ll *a,ll *b)
		{
			if(l==r) {t[k]=node(a[l],b[l],a[l]+b[l]);return;}
			build(k1,l,mid,a,b);build(k2,mid+1,r,a,b);
			t[k]=t[k1]+t[k2];
			return;
		}
		node query(int k,int l,int r,int x,int y)
		{
			x=max(x,l);y=min(r,y);
			if(x>y) return node(-INF,-INF,-INF);
			if(x<=l&&y>=r) return t[k];
			return query(k1,l,mid,x,y)+query(k2,mid+1,r,x,y);
		}
}T2;
int n,q,a,b;
ll c,ans,sum[3][N],pre[N],suf[N],f[N];
vector<pii> e[N];
template<class T>
void Read(T &x)
{
	x=0;int f=1;char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) x=(x<<3)+(x<<1)+ch-'0';
	x*=f;return;
}
int main()
{
	Read(n);Read(q);T1.init();
	for(int i=0;i<3;i++)
		for(int j=1;j<=n;j++)
			Read(sum[i][j]),sum[i][j]+=sum[i][j-1];
	for(int i=1;i<=n;i++) pre[i]=sum[0][i]-sum[1][i-1],suf[i]=sum[1][i]-sum[2][i-1]+sum[2][n],T1.change(1,1,n,i,pre[i]);
	for(int i=1;i<=q;i++)
	{
		Read(a);Read(b);Read(c);
		e[b].push_back(mp(a,c));
	}
	for(int i=1;i<=n;i++)
	{
		f[i]=T1.mx[0];
		for(auto j:e[i])
		{
			a=j.first;c=j.second;
			f[i]=max(f[i],T1.query(1,1,n,a,i)-c);
		}
		T1.change(1,1,n,i+1,f[i]);
	}
	ans=T1.mx[0];
	T2.build(1,1,n,pre,suf);
	for(int i=1;i<=n;i++)
	{
		for(auto j:e[i])
		{
			a=j.first;c=j.second;
			ans=max(ans,T2.query(1,1,n,a,i).mx-c);
		}
	}
	T2.build(1,1,n,f,suf);
	for(int i=1;i<=n;i++)
	{
		for(auto j:e[i])
		{
			a=j.first;c=j.second;
			ans=max(ans,T2.query(1,1,n,a-1,i).mx-c);
		}
	}
	printf("%lld",ans);
	return 0;
}