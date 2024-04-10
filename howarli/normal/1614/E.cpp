#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int N=200500,MX=1e9;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 rand_num(seed);  // 
uniform_int_distribution<int> dist(0, 1000000000);
int RD(int q){return rand_num()%q;}


int n,m;
struct SGTv
{
	int l,r;
	int L,R;
	int la;
	SGTv()
	{
		l=r=L=R=la=0;
	}
}tr[N*30*2];
int root,tr0;
void nwit(SGTv &nw)
{
	if(nw.L==nw.R)
	{
		return;
	}

	int mid=(nw.L+nw.R)>>1;
	if(!nw.l)
	{
		nw.l=++tr0;
		tr[tr0].L=nw.L;
		tr[tr0].R=mid;
	}
	if(!nw.r)
	{
		nw.r=++tr0;
		tr[tr0].L=mid+1;
		tr[tr0].R=nw.R;
	}
}

void PD(int l,int r,int e)
{
	if(!tr[e].la)return;
	if(l!=r)
	{
		nwit(tr[e]);
		tr[tr[e].l].la+=tr[e].la;
		tr[tr[e].r].la+=tr[e].la;
	}
	tr[e].L+=tr[e].la;
	tr[e].R+=tr[e].la;
	tr[e].la=0;
}
void merge(int e)
{
	tr[e].L=tr[tr[e].l].L;
	tr[e].R=tr[tr[e].r].R;
}
int find(int l1,int l=0,int r=MX,int e=root) // find >l1
{
	if(l==r)
	{
		return l;
	}
	nwit(tr[e]);
	int mid=(l+r)>>1;

	PD(l,mid,tr[e].l);
	PD(mid+1,r,tr[e].r);

	return (tr[tr[e].l].R<=l1)?find(l1,mid+1,r,tr[e].r):find(l1,l,mid,tr[e].l);
}
void change(int l1,int r1,int l2,int l=0,int r=MX,int e=root)
{
	if(l1>r1)return;
	nwit(tr[e]);
	if(l1<=l && r<=r1)
	{
		tr[e].la+=l2;
		PD(l,r,e);
		return;
	}
	
	int mid=(l+r)>>1;

	PD(l,mid,tr[e].l);PD(mid+1,r,tr[e].r);

	if(l1<=mid)change(l1,r1,l2,l,mid,tr[e].l);
	if(mid<r1)change(l1,r1,l2,mid+1,r,tr[e].r);
	merge(e);
}

int search(int l1,int l=0,int r=MX,int e=root)
{
	PD(l,r,e);
	if(r-l==tr[e].R-tr[e].L)
	{
		return tr[e].L-l+l1;
	}
	if(l==r)
	{
		return tr[e].L;
	}
	int mid=(l+r)>>1;
	return (mid<l1)?search(l1,mid+1,r,tr[e].r):search(l1,l,mid,tr[e].l);
}
int main()
{
	int q,w,_;
	tr0=1;
	root=1;
	tr[1].L=0;
	tr[1].R=MX;

	read(n);
	int ans=0;
	fo(I,1,n)
	{
		int nw;
		read(nw);
		
		if(tr[1].R>nw)
		{
			int R=find(nw);
			change(R,MX,-1);
		}

		if(tr[1].R<nw)
		{
			change(0,MX,1);
		}else{
			int L=find(nw-1);
			change(0,L-1,1);
		}

		read(m);
		fo(j,1,m)
		{
			read(q);
			q=(ans+q)%(MX+1);
			ans=search(q);
			printf("%d\n",ans);
		}
	}
	
	return 0;
}