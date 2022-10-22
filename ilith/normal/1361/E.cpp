#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(int i=a,i##i=b;i>=i##i;--i)
using namespace std;
const int N=100010;
int T,n,m,u,v,vs[N],is[N],d[N],sz[N],sn[N],G;
vector<int>a[N],f;
multiset<int>s[N];
mt19937 rnd(time(0));
int chk(int x){
	int r=vs[x]=is[x]=1;
	for(int to:a[x])if(!vs[to])d[to]=d[x]+1,r&=chk(to);
	else r&=is[to];
	return is[x]=0,r;
}
void get(int x){
	sz[x]=1;
	int t=0;
	for(int to:a[x])if(d[to]>d[x]){
		get(to),sz[x]+=sz[to];
		if(sz[to]>sz[t])t=to;
	}
	swap(s[x],s[t]);
	for(int to:a[x])if(d[to]>d[x]){
		if(to!=t)for(int k:s[to])s[x].insert(k);
	}
	else s[x].insert(to);
	s[x].erase(x);
	if(s[x].size()==1)is[x]=*s[x].begin();
}
void dfs(int x){
	is[x]=is[is[x]]||x==u;
	for(int to:a[x])if(d[to]>d[x])dfs(to);
}
void work(){
	scanf("%d%d",&n,&m),G=40,f.clear();
	FOR(i,1,n)a[i].clear(),s[i].clear();
	while(m--)scanf("%d%d",&u,&v),a[u].push_back(v);
	for(d[u=1]=0;memset(vs,0,sizeof vs),!chk(u);d[u=rnd()%n+1]=0)if(!--G)break;
	if(!G)return void(printf("-1"));
	get(u),dfs(u);
	FOR(i,1,n)if(is[i])f.push_back(i),is[i]=0;
	if((int)f.size()*5<n)return void(printf("-1"));
	for(int k:f)printf("%d ",k);
}
signed main(){
	for(scanf("%d",&T);T--;)work(),puts("");
	return 0;
}