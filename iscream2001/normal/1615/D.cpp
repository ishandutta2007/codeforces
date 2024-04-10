#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define LD long double
using namespace std;
LL qpow(LL x,LL y,LL P=998244353){
	LL re;
	for(re=1;y;y>>=1){if(y&1) re=re*x%P;x=x*x%P;}
	return re;
}
const LL P=1e9+7;
const int N=2e5+10;
const int INF=1e9;

void init(){
}

int n,m,flag;
struct edge{
	int l,r,val,c;
}e[N];
int cal1(int x){
	int re=0;
	while(x){
		if(x&1) re^=1;
		x>>=1;
	}
	return re;
}
vector< pair<int,int> > V[N];

int fa[N],sz[N],co[N];

pair<int,int> find(int x){
	if(fa[x]==x){
		return make_pair(x,0);
	}
	pair<int,int> tmp=find(fa[x]);
	tmp.second^=co[x];
	return tmp;
}
void dfs(int x,int F){
	int y,z,u,v;
	pair<int,int> hhh,www;
	for(int i=0;i<V[x].size();++i){
		y=V[x][i].first;
		z=V[x][i].second;
		if(y==F) continue;
		if(e[z].val<0){
			u=x;v=y;
			hhh=find(u);
			www=find(v);
			if(hhh.first==www.first){
				e[z].val=hhh.second^www.second;
			}
			else{
				e[z].val=0;
				if(sz[hhh.first]<sz[www.first]) swap(hhh,www);
				u=hhh.first;v=www.first;
				fa[v]=u;sz[u]+=sz[v];co[v]=hhh.second^www.second;
			}
		}
		dfs(y,x);
	}
	return;
	
}
void MAIN(){
	int u,v,op;
	flag=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) V[i].clear();
	for(int i=1;i<n;++i){
		scanf("%d%d%d",&e[i].l,&e[i].r,&e[i].val);
		e[i].c=0;
		if(e[i].val>=0){
			e[i].c=cal1(e[i].val);
		}
		V[e[i].l].push_back(make_pair(e[i].r,i));
		V[e[i].r].push_back(make_pair(e[i].l,i));
	}
	for(int i=1;i<=n;++i){
		fa[i]=i;
		sz[i]=1;
		co[i]=0;
	}
	pair<int,int> hhh,www;
	for(int i=1;i<n;++i){
		if(e[i].val<0) continue;
		u=e[i].l;v=e[i].r;
		hhh=find(u);
		www=find(v);
		if(hhh.first==www.first){
			if(hhh.second^www.second==e[i].c){
				continue;
			}
			else{
				flag=1;
				continue;
			}
		}
		else{
			if(sz[hhh.first]<sz[www.first]) swap(hhh,www);
			u=hhh.first;v=www.first;
			fa[v]=u;sz[u]+=sz[v];co[v]=hhh.second^www.second^e[i].c;
		}
	}
	while(m--){
		scanf("%d%d%d",&u,&v,&op);
		hhh=find(u);
		www=find(v);
		if(hhh.first==www.first){
			if(hhh.second^www.second==op){
				continue;
			}
			else{
				flag=1;
				continue;
			}
		}
		else{
			if(sz[hhh.first]<sz[www.first]) swap(hhh,www);
			u=hhh.first;v=www.first;
			fa[v]=u;sz[u]+=sz[v];co[v]=hhh.second^www.second^op;
		}
	}
	dfs(1,0);
	if(flag){
		puts("NO");
		return;
	}
	puts("YES");
	for(int i=1;i<n;++i){
		printf("%d %d %d\n",e[i].l,e[i].r,e[i].val);
	}
	return;
}
/*
*/
int main(){
    init();
    int ttt=1;scanf("%d",&ttt);
    while(ttt--) MAIN();
    return 0;    
}