#include <bits/stdc++.h>
#define fo(i,a,b)  for(int i=a;i<=b;++i)
#define fod(i,a,b)  for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
using namespace std;
typedef long long LL;
const int N=300500,INF=1e9+7;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
int a[N],p[N];
int B[N*3][2],A[N],B0;
int jp[N][2];
void link(int q,int w)
{
	if(w&&q<=n)B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;
}
int gfl(int q){return q==jp[q][0]?q:jp[q][0]=gfl(jp[q][0]);}
int gfr(int q){return q==jp[q][1]?q:jp[q][1]=gfr(jp[q][1]);}
bool PX(int q,int w){return a[q]<a[w];}
int dis[N];
struct DIJv
{
	int i,v;
};
bool operator<(DIJv q,DIJv w){return q.v>w.v;}
priority_queue<DIJv>d;
void DIJ()
{
	fo(i,1,n)dis[i]=INF;
	dis[n]=0;
	DIJv t;
	t.i=n;t.v=0;
	d.push(t);
	for(;!d.empty();)
	{
		t=d.top();d.pop();
		if(dis[t.i]!=t.v)continue;
		int q=t.i;
		efo(i,q)if(dis[B[i][1]]>dis[q]+1)
		{
			t.v=dis[B[i][1]]=dis[q]+1;
			t.i=B[i][1];
			d.push(t);
		}
	}
}

int main()
{
	int q,w,_;
	// int SRT=clock();
	read(n);
	fo(i,1,n)read(a[i]),p[i]=i;
	sort(p+1,p+1+n,PX);
	fo(i,0,n+1)jp[i][0]=jp[i][1]=i;
	fo(i,1,n)
	{
		q=p[i];
		jp[q][0]=gfl(q-1);
		jp[q][1]=gfr(q+1);
		if(min(a[jp[q][0]],a[jp[q][1]])>a[q])link(jp[q][1],jp[q][0]);
	}
	fo(i,0,n+1)jp[i][0]=jp[i][1]=i;
	fod(i,n,1)
	{
		q=p[i];
		jp[q][0]=gfl(q-1);
		jp[q][1]=gfr(q+1);
		if(max(a[jp[q][0]],a[jp[q][1]])<a[q])link(jp[q][1],jp[q][0]);
	}
	fo(i,1,n-1)link(i+1,i);
	DIJ();
	printf("%d\n",dis[1]);
	return 0;
}