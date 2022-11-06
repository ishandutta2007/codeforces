#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define DEBUG(x) cerr<<#x" == "<<x<<endl
using namespace std;
typedef long long ll;
inline int read(){
	int w=0,p=0;char c;
	while(!isdigit(c=getchar()))if(c=='-')p=1;
	while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
	return p?-w:w;
}
const int N=1e5+7;
vector<int> g[N];
int n,m;
struct ask{int h,id;};
vector<ask> q[N];
int siz[N],dep[N],up[N][25];
void dfs_pre(int x){
	siz[x]=1;
	REP(i,1,18)up[x][i]=up[up[x][i-1]][i-1];
	for(int y:g[x])
		up[y][0]=x,dep[y]=dep[x]+1,dfs_pre(y),siz[x]+=siz[y];
}
int cnt[N],ans[N];
void add(int x,int w){
	cnt[dep[x]]+=w;
	for(int y:g[x])add(y,w);
}
void dfs(int x){
	int son=0;
	for(int y:g[x])if(siz[y]>siz[son])son=y;
	for(int y:g[x])if(y!=son)dfs(y),add(y,-1);
	if(son)dfs(son);
	for(int y:g[x])if(y!=son)add(y,1);
	for(auto t:q[x])ans[t.id]=cnt[t.h]-1;
	++cnt[dep[x]];
}
int main(){
	n=read();
	REP(i,1,n)g[read()].push_back(i);
	m=read();
	dfs_pre(0);siz[0]=0;
	REP(i,1,m){
		int x=read(),p=read();
		int t=x;
		DEC(j,18,0)if(p>=(1<<j))t=up[t][j],p-=1<<j;
		if(t)q[t].push_back({dep[x],i});else ans[i]=0;
	}
	dfs(0);
	REP(i,1,m)printf("%d\n",ans[i]);
	return 0;
}