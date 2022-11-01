#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define link(x,y)(ne[++js]=la[x],la[x]=js,to[js]=y)
#define ff(i,x)for(int i=la[x];i;i=ne[i])
#define ll long long
#define max(a,b)(B=b,a>B?a:B)
#define P pair<int,int>
using namespace std;
const int N=1e5+5;
int n,m,f[N],g[N],an;
int x,y,w,fx,fy;
int rt[N],B,ts;
struct no{
	int l,r,x;
}t[N*51];
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
int find(int v,int l,int r,int x){
	if(!t[v].x||r<=x)return t[v].x;
	int m=l+r>>1;
	return x<=m?find(t[v].l,l,m,x):max(t[t[v].l].x,find(t[v].r,m+1,r,x));
}
void ch(int &v,int l,int r,int x,int y){
	t[++ts]=t[v];v=ts;t[v].x=max(t[v].x,y);
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m)ch(t[v].l,l,m,x,y);else ch(t[v].r,m+1,r,x,y);
}
int main(){
//	freopen("a.in","r",stdin);
	R(n);R(m);
	fo(i,1,m){
		R(x);R(y);R(w);fx=0;
		if(w)
			fx=find(rt[x],0,100000,w-1);
		ch(rt[y],0,100000,w,fx+1);
	}
	fo(i,1,n)an=max(an,t[rt[i]].x);
	printf("%d",an);
}