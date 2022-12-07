#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<LL,LL> pii;
const int N=1000500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}



int n,m;
int a1[3][N];
LL as[3][N],a[2][N];
LL tr[N*4];
LL f[N];
LL MAX(LL &q,LL w){return q=max(q,w);}
void build(int l=1,int r=n,int e=1)
{
	if(l==r)
	{
		tr[e]=f[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,e<<1);
	build(mid+1,r,e<<1|1);
	tr[e]=max(tr[e<<1],tr[e<<1|1]);
}
LL find(int l1,int r1,int l=1,int r=n,int e=1)
{
	if(l1<=l&&r<=r1)
	{
		return tr[e];
	}
	int mid=(l+r)>>1;
	LL ans=-1e18;
	if(l1<=mid)ans=max(ans,find(l1,r1,l,mid,e<<1));
	if(mid<r1)ans=max(ans,find(l1,r1,mid+1,r,e<<1|1));
	return ans;
}
void change(int l1,LL l2,int l=1,int r=n,int e=1)
{
	if(l==r)
	{
		tr[e]=max(tr[e],l2);
		return;
	}
	int mid=(l+r)>>1;
	if(l1<=mid)change(l1,l2,l,mid,e<<1);
	else change(l1,l2,mid+1,r,e<<1|1);
	tr[e]=max(tr[e<<1],tr[e<<1|1]);
}
LL d[N];

int sc[N][3];
vector<int>Bt[N];


LL b[N*4][3];

void build2(int l=1,int r=n,int e=1)
{
	if(l==r)
	{
		b[e][0]=max(f[l-1],a[0][l]);
		b[e][1]=a[1][l];
		b[e][2]=b[e][0]+b[e][1];
		return;
	}
	int mid=(l+r)>>1;
	build2(l,mid,e<<1);
	build2(mid+1,r,e<<1|1);
	b[e][2]=max({b[e<<1][2],b[e<<1|1][2],b[e<<1][0]+b[e<<1|1][1]});
	b[e][0]=max(b[e<<1][0],b[e<<1|1][0]);
	b[e][1]=max(b[e<<1][1],b[e<<1|1][1]);
}
LL ans;
pii get(int l1,int r1,int l=1,int r=n,int e=1)
{
	if(l1<=l&&r<=r1)
	{
		ans=max(ans,b[e][2]);
		return {b[e][0],b[e][1]};
	}
	int mid=(l+r)>>1;
	pii L={-1e18,-1e18},R=L;
	if(l1<=mid)L=get(l1,r1,l,mid,e<<1);
	if(mid<r1)R=get(l1,r1,mid+1,r,e<<1|1);

	ans=max(ans,L.first+R.second);
	return {max(L.first,R.first),max(L.second,R.second)};
}
int main()
{
	int q,w,_;
	read(n),read(m);
	fo(j,0,2)fo(i,1,n)as[j][i]=as[j][i-1]+read(a1[j][i]);
	fo(i,1,n)
	{
		a[0][i]=as[0][i]-as[1][i-1];
		a[1][i]=as[2][n]-as[2][i-1]+as[1][i];
	}
	
	fo(i,1,m)
	{
		read(q),read(w);
		sc[i][0]=q,sc[i][1]=w;
		read(sc[i][2]);
		Bt[w].push_back(i);
	}

	fo(i,0,n+1)f[i]=-1e18;
	build();

	fo(i,1,n)
	{
		for(;d[0]&& a[0][d[d[0]]]<=a[0][i];--d[0]);
		d[++d[0]]=i;
		for(auto nw:Bt[i])
		{
			int l=sc[nw][0];
			int e=sc[nw][2];
			q=lower_bound(d+1,d+1+d[0],l)-d;
			MAX(f[i],a[0][d[q]]-e);

			LL t=find(l-1,i);
			MAX(f[i],t-e);
		}
		if(f[i]>-1e18)
		{
			change(i,f[i]);
		}
	}

	LL Ans=-1e18;
	build2();
	fo(i,1,m)
	{
		ans=-1e18;
		get(sc[i][0],sc[i][1]);
		Ans=max(Ans,ans-sc[i][2]);
	}

	cout<<Ans<<endl;
	return 0;
}