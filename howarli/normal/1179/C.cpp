#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define max(q,w) ((q)<(w)?(w):(q))
#define min(q,w) ((q)>(w)?(w):(q))
using namespace std;
const int N=300500,mo=1e9+7;
int read(int &n)
{
	int w=1;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return n=n*w;
}
int n,n1,m,mx;
int a[N],a1[N];
struct SGT
{
	int mx,v;
}tr[1000000*4];
void merge(int e)
{
	tr[e].mx=max(tr[e<<1|1].mx,tr[e<<1].mx+tr[e<<1|1].v);
	tr[e].v=tr[e<<1].v+tr[e<<1|1].v;
}
void change(int l1,int l2,int l=1,int r=mx,int e=1)
{
	if(l==r)
	{
		tr[e].mx=tr[e].v+=l2;
		return;
	}
	int mid=(l+r)>>1;
	if(l1<=mid)change(l1,l2,l,mid,e<<1);
	else change(l1,l2,mid+1,r,e<<1|1);
	merge(e);
}
int find(int l=1,int r=mx,int e=1,int t=0)
{
	if(tr[e].mx+t<=0)return -1;
	if(l==r)return l;
	int mid=(l+r)>>1;
	return (tr[e<<1|1].mx+t<=0)?find(l,mid,e<<1,t+tr[e<<1|1].v):find(mid+1,r,e<<1|1,t);
}
int main()
{
	int q,w;
	read(n),read(n1);
	mx=1e6;
	fo(i,1,n)read(a[i]),change(a[i],1);
	fo(i,1,n1)read(a1[i]),change(a1[i],-1);
	read(m);
	fo(i,1,m)
	{
		read(q),read(w);
		if(q==1)
		{
			change(a[w],-1);
			read(a[w]);
			change(a[w],1);
		}else
		{
			change(a1[w],1);
			read(a1[w]);
			change(a1[w],-1);
		}
		printf("%d\n",find());
	}
	return 0;
}