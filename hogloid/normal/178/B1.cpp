#include<iostream>
#include<algorithm>
#include<stack>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int n,m,k;
typedef vector<int> vi;
vi g[1005];
int order[1005],low[1005],cnt;
stack<int> cur;
int group[1005],gcnt;
int dfs(int v,int p){
	order[v]=cnt++;
	low[v]=order[v];
	cur.push(v);
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		if(order[to]!=-1){
			low[v]=min(low[v],order[to]);
		}else{
			low[v]=min(low[v],dfs(to,v));
		}
	}
	if(low[v]<order[v]) return low[v];
	while(!cur.empty() && cur.top()!=v){
		group[cur.top()]=gcnt;
		cur.pop();
	}
	group[cur.top()]=gcnt;
	cur.pop();
	++gcnt;
	return low[v];
}
vi g2[1005];
int depth[1005];
int par[12][1005];
void dfs(int v,int p,int dep){
	par[0][v]=p;
	depth[v]=dep;
	REP(i,g2[v].size()){
		int to=g2[v][i];
		if(to==p) continue;
		dfs(to,v,dep+1);
	}
}
int LCA(int a,int b){
	if(depth[a]>depth[b]) swap(a,b);
	int dif=depth[b]-depth[a];
	REP(i,12) if(dif>>i&1){
		b=par[i][b];
	}
	if(a==b) return a;
	for(int i=11;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];
		b=par[i][b];
	}
	return par[0][a];
}
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	memset(order,-1,sizeof(order));
	dfs(0,-1);
	REP(i,n) REP(j,g[i].size()){
		if(group[g[i][j]]!=group[i]){
			int u=group[i],v=group[g[i][j]];
			g2[u].pb(v);
			g2[v].pb(u);
		}
	}
	REP(i,gcnt){
		sort(g2[i].begin(),g2[i].end());
		g2[i].erase(unique(g2[i].begin(),g2[i].end()),g2[i].end());
	}
	dfs(0,-1,0);
	REP(i,11) REP(j,gcnt){
		if(par[i][j]==-1) par[i+1][j]=-1;
		else par[i+1][j]=par[i][par[i][j]];
	}
	scanf("%d",&k);
	REP(hoge,k){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		a=group[a];b=group[b];
		printf("%d\n",depth[a]+depth[b]-depth[LCA(a,b)]*2);
	}

	return 0;
}