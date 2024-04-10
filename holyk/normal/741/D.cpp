#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=5e5+7;
int n,dep[N],siz[N],c[N];
struct node{int v,w;};
vector<node> g[N];
void dfsp(int x){
	siz[x]=1;
	for(auto e:g[x])c[e.v]=c[x]^(1<<e.w),dep[e.v]=dep[x]+1,dfsp(e.v),siz[x]+=siz[e.v];
}
int ans[N],now,p[1<<22|1];
void add(int x){	
	smax(p[c[x]],dep[x]);
	for(auto e:g[x])add(e.v);
}
void del(int x){
	p[c[x]]=0xcfcfcfcf;
	for(auto e:g[x])del(e.v);
}
void calc(int x){
	REP(i,0,21)smax(ans[now],p[c[x]^(1<<i)]+dep[x]-dep[now]*2);
	smax(ans[now],p[c[x]]+dep[x]-dep[now]*2);
	for(auto e:g[x])calc(e.v);
}
void dfs(int x){
	int son=0;
	for(auto e:g[x])if(siz[e.v]>siz[son])son=e.v;
	for(auto e:g[x])if(e.v!=son)dfs(e.v),smax(ans[x],ans[e.v]),del(e.v);
	if(son)dfs(son),smax(ans[x],ans[son]);
	now=x;
	for(auto e:g[x])if(e.v!=son)calc(e.v),add(e.v);
	smax(p[c[x]],dep[x]);smax(ans[x],p[c[x]]-dep[x]);
	REP(i,0,21)smax(ans[x],p[c[x]^(1<<i)]-dep[x]);
}
int main(){
	n=read();
	REP(i,2,n){
		char s[3];int x;
		scanf("%d%s",&x,s);
		g[x].push_back({i,s[0]-'a'});
	}
	memset(p,0xcf,sizeof p);
	dfsp(1);dfs(1);
	REP(i,1,n)printf("%d\n",ans[i]);
	return 0;
}