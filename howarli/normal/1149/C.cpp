#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
#define PR(...) printf(__VA_ARGS__)
#define EPR(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long LL;
const int N=200500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int a[N];
struct SGT
{
	int v;
	int l,r,lp,lm,rp,rm;
}tr[N*4];
int MAX(int &q,int w){return q=max(q,w);}
void merge(int e)
{
	int l=e<<1,r=e<<1|1;
	
	tr[e].l=tr[l].l+max(0,tr[r].l-tr[l].r);
	tr[e].r=tr[r].r+max(0,tr[l].r-tr[r].l);
	
	tr[e].lp=max(tr[l].lp,max(tr[r].lp+tr[l].l-tr[l].r,tr[r].lm+tr[l].l+tr[l].r));
	tr[e].lm=max(tr[l].lm,tr[r].lm-tr[l].l+tr[l].r);
	
	tr[e].rp=max(tr[r].rp,max(tr[l].rp-tr[r].l+tr[r].r,tr[l].rm+tr[r].l+tr[r].r));
	tr[e].rm=max(tr[r].rm,tr[l].rm+tr[r].l-tr[r].r);
	
	tr[e].v=max(max(tr[l].rp+tr[r].lm,tr[l].rm+tr[r].lp),max(tr[l].v,tr[r].v));
}
void change(int l1,int l2,int l=1,int r=n,int e=1)
{
	if(l==r)
	{
		if(l2==1)
		{
			tr[e].r=1,tr[e].l=0;
			tr[e].rp=tr[e].lp=1;
			tr[e].lm=1;
			tr[e].rm=0;
		}
		else
		{
			tr[e].r=0,tr[e].l=1;
			tr[e].rp=tr[e].lp=1;
			tr[e].lm=0;
			tr[e].rm=1;
		}
		return;
	}
	int mid=(l+r)>>1;
	if(l1<=mid)change(l1,l2,l,mid,e<<1);
	else change(l1,l2,mid+1,r,e<<1|1);
	merge(e);
}
int main()
{
	int q,w;
	read(n),read(m);
	char ch=' ';
	for(;ch!='('&&ch!=')';ch=getchar());
	n=n*2-2;
	fo(i,1,n)
	{
		a[i]=(ch=='(')?1:-1;
		ch=getchar();
		change(i,a[i]);
	}
	PR("%d\n",tr[1].v);
	fo(I,1,m)
	{
		read(q),read(w);
		swap(a[q],a[w]);
		change(q,a[q]);
		change(w,a[w]);
		PR("%d\n",tr[1].v);
	}
	return 0;
}