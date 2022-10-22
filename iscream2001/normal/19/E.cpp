#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+10;
const double eps=1e-6;

int n,m,cnt;

struct edge{
	int u,v,id;
}e[N];

vector< pair<int,int> > V[N];

int fa[N],dep[N];
int co[N];
bool vis[N];
int sum[N];
int tp,wh;
int q[N];
void dfs(int x){
	vis[x]=1;
	for(int i=0;i<V[x].size();++i){
		if(vis[V[x][i].first]==0){
			fa[V[x][i].first]=V[x][i].second;
			co[V[x][i].first]=co[x]^1;
			dep[V[x][i].first]=dep[x]+1;
			dfs(V[x][i].first);
			sum[x]+=sum[V[x][i].first];
			continue;
		}
		if(dep[V[x][i].first]<dep[x]-1){
			if(co[x]==co[V[x][i].first]){
				++cnt;
				++sum[x];
				--sum[V[x][i].first];
				wh^=V[x][i].second;
				//q[++tp]=V[x][i].second;
			}
			else{
				--sum[x];
				++sum[V[x][i].first];
			}
		}
	}
	return;
}

void MAIN(){
	scanf("%d%d",&n,&m);cnt=0;
	for(int i=1;i<=m;++i){
		scanf("%d%d",&e[i].u,&e[i].v);e[i].id=i;
		V[e[i].u].push_back(make_pair(e[i].v,i));
		V[e[i].v].push_back(make_pair(e[i].u,i));
	}
	for(int i=1;i<=n;++i){
		if(!vis[i]){
			dep[i]=1;
			dfs(i);
		}
	}
	if(cnt==0){
		printf("%d\n",m);
		for(int i=1;i<=m;++i){
			printf("%d ",i);
		}
		puts("");
		return;
	}
	tp=0;
	if(cnt==1) q[++tp]=wh;
	for(int i=1;i<=n;++i){
		if(sum[i]==cnt){
			q[++tp]=fa[i];
		}
	}
	sort(q+1,q+1+tp);
	printf("%d\n",tp);
	for(int i=1;i<=tp;++i)printf("%d ",q[i]);
	puts("");
	return;
}
int main(){
	int ttt=1;//scanf("%d",&ttt);
	while(ttt--){
		MAIN();
	}
    return 0;
}