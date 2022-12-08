#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
#define SD(q) ((q)==b[b[q].fa].r)
using namespace std;
typedef pair<int,int> PR;
const int N=200500,INF=2147483640;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n;
int Ans[N];
struct qqww
{
	int v,c;
}a[N];
struct Treap
{
	int l,r,fa,rd;
	int i,v,la,sla,ans;
}b[N];
int root;
int RD(){return rand();}
bool PX(Treap q,Treap w){return q.v>w.v;}
bool PXa(qqww q,qqww w){return q.v>w.v||(q.v==w.v&&q.c<w.c);}
int za[N];
void Pre()
{
	fo(i,1,n+1)
	{
		int q=0;//b[i].rd=RD();
		for(;za[0]&&(b[za[za[0]]].rd<b[i].rd||i>n);--za[0])
		{
			q=za[za[0]];
			if(za[0]-1)b[b[q].fa=za[za[0]-1]].r=q;
		}
		if(i<=n)b[i].l=q,b[q].fa=i,za[++za[0]]=i;
	}
	root=za[1];
}
void doit(int q)
{
	if(!q||(!b[q].la&&!b[q].sla))return;
	b[q].ans+=b[q].sla;
	if(b[q].l)b[b[q].l].sla+=b[q].sla;
	if(b[q].r)b[b[q].r].sla+=b[q].sla;
	b[q].sla=0;
	b[q].v+=b[q].la;
	if(b[q].l)b[b[q].l].la+=b[q].la;
	if(b[q].r)b[b[q].r].la+=b[q].la;
	b[q].la=0;	
}
PR Split(int q,int e)
{
	if(!q)return PR(0,0);
	PR t;doit(q);b[q].fa=0;
	if(b[q].v>=e)t=Split(b[q].r,e),b[b[q].r=t.first].fa=q,t.first=q;
	else t=Split(b[q].l,e),b[b[q].l=t.second].fa=q,t.second=q;
	return t;
}
int Amalg(int q,int w)
{
	doit(q);b[q].fa=0;
	doit(w);b[w].fa=0;
	if(!q||!w)return q+w;
	if(b[q].rd>b[w].rd)
	{
		b[b[q].r=Amalg(b[q].r,w)].fa=q;
		return q;
	}
	b[b[w].l=Amalg(q,b[w].l)].fa=w;
	return w;
}
int findMX(int q)
{
	for(doit(q);b[q].l;q=b[q].l)doit(b[q].l);
	return b[q].v;
}
int ADDrt;
void ADD(int q)
{
	PR t=Split(ADDrt,b[q].v);
	b[q].l=b[q].r=b[q].fa=0;
	q=Amalg(t.first,q);
	ADDrt=Amalg(q,t.second);
}
int Troot;
void findP(int q,int e)
{
	doit(q);
	if(b[q].r)findP(b[q].r,e);
	if(b[q].v>=e)return;
	b[b[q].l].fa=b[q].fa;
	if(!b[q].fa)Troot=b[q].l;
	else if(SD(q))b[b[q].fa].r=b[q].l;
	else b[b[q].fa].l=b[q].l;
	if(b[q].l)findP(b[q].l,e);
	ADD(q);
}
void Tdfs(int q)
{
	if(!q)return;
	doit(q);
	Ans[b[q].i]=b[q].ans;
	Tdfs(b[q].l);
	Tdfs(b[q].r);
}
int main()
{
	// freopen("!.in","r",stdin);
	// freopen("1.out","w",stdout);
	// int q,w;
	srand(19890604);
	read(m);
	fo(i,1,m)read(a[i].c),read(a[i].v);
	read(n);
	fo(i,1,n)b[i].i=i,read(b[i].v),b[i].rd=RD();
	sort(b+1,b+1+n,PX);
	Pre();
	sort(a+1,a+1+m,PXa);
	fo(I,1,m)
	{
		PR t=Split(root,a[I].c);
		b[t.first].sla++;
		b[t.first].la-=a[I].c;
		if(!t.second)continue;	
		ADDrt=t.second;
		int mx=findMX(t.second);
		Troot=t.first;
		findP(t.first,mx);
		root=Amalg(Troot,ADDrt);
	}
	Tdfs(root);
	fo(i,1,n)printf("%d\n",Ans[i]);
	return 0;
}