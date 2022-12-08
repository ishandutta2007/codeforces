#include <bits/stdc++.h>
#define fo(i,a,b)  for(int i=a;i<=b;++i)
#define fod(i,a,b)  for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
using namespace std;
typedef long long LL;
const int N=500500,INF=1e9;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return q?n=-n:n;
}
int n,m,ans;
int B[N*3][3],A[N],B0;
void link(int q,int w,int e)
{
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w,B[B0][2]=e;
}
int dis[N][2];
struct DIJv
{
	int i,v,cl;
};
bool operator<(DIJv q,DIJv w){return q.v>w.v;}
priority_queue<DIJv>d;
bool z[N];
void DIJ()
{
	fo(i,1,n)dis[i][0]=dis[i][1]=INF;
	dis[n][1]=0;
	dis[n][0]=-1;
	z[n]=1;
	DIJv t;
	t.i=n;t.v=0;t.cl=1;
	d.push(t);
	for(;!d.empty();)
	{
		t=d.top();d.pop();
		int q=t.i,w=t.cl;
		if(dis[q][w]!=t.v)continue;
		if(!z[q]){z[q]=1;continue;}
		efo(i,q)if(dis[B[i][1]][B[i][2]]>dis[q][w]+1)
		{
			t.v=dis[B[i][1]][B[i][2]]=dis[q][w]+1;
			t.i=B[i][1];t.cl=B[i][2];
			d.push(t);
		}
	}
}

int main()
{
	int q,w,e;
	// int SRT=clock();
	read(n),read(m);
	fo(i,1,m)
	{
		read(w),read(q),read(e);
		link(q,w,e);
	}
	DIJ();
	if(max(dis[1][0],dis[1][1])==INF)printf("-1\n");
	else printf("%d\n",max(dis[1][0],dis[1][1]));
	fo(i,1,n)printf("%d",(dis[i][0]>dis[i][1])?0:1);
	return 0;
}