#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=5005,M=1e6+5;
int n,k,mx,a[N];
struct node{short x,y;int nxt;}g[12502510];
int head[M],fa[N],tg[N],t,tot;
inline int find(int x){
	if(tg[x]!=t)return tg[x]=t,fa[x]=x;
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
bool check(int m){
	int cnt=0,u=0;++t;
	for(int x=m;x<=mx;x+=m)
		for(int i=head[x];i;i=g[i].nxt){
			int a=find(g[i].x),b=find(g[i].y);
			if(a!=b)fa[a]=b,++u;
			if(++cnt>(k+1)*k>>1||u>k)return 0;
		}
	return 1;
}
inline void add(int u,short x,short y){g[++tot].x=x,g[tot].y=y,g[tot].nxt=head[u];head[u]=tot;}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>k;
	REP(i,1,n)cin>>a[i],a[i]>mx&&(mx=a[i]);
	REP(i,1,n)REP(j,i+1,n)add(abs(a[i]-a[j]),i,j);
	REP(i,n-k,mx)if(check(i))return cout<<i,0;
}