#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
typedef long long ll;
using namespace std;
const int N=300010;
int n,m,u,v,sz[N];
ll w[N],ad[N],ans;
vector<int>a[N],b[N];
struct cmp{bool operator()(int x,int y)const{return w[x]==w[y]?x<y:w[x]<w[y];}};
set<int,cmp>s[N];
void dfs(int x,int f){
	sz[x]=1;
	rgi t=0;
	for(rgi to:a[x])if(to!=f){
		dfs(to,x),sz[x]+=sz[to];
		if(sz[to]>sz[t])t=to;
	}
	swap(ad[x],ad[t]),swap(s[x],s[t]);
	for(rgi to:a[x])if(to!=f){
		for(rgi k:s[to])w[k]-=ad[to]-ad[x],s[x].insert(k);
	}	
	for(rgi k:b[x])if(k<0)s[x].erase(-k);
	else w[k]+=ad[x],s[x].insert(k);
	if(s[x].empty())printf("%lld",x==1?ans:-1),exit(0);	
	rgi k=*s[x].begin();
	ans+=w[k]-ad[x],ad[x]=w[k];
}
signed main(){
	scanf("%d%d",&n,&m);
	for(rgi i=1;i<n;++i)scanf("%d%d",&u,&v),a[u].pbk(v),a[v].pbk(u);
	for(rgi i=1;i<=m;++i)scanf("%d%d%lld",&u,&v,w+i),b[u].pbk(i),b[v].pbk(-i);
	dfs(1,0);
}