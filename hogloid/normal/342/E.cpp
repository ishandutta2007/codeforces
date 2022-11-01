#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define ALL(t) (t).begin(),(t).end()
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

int n,m;
vector<int> g[100005];
const int B=300;

int newvs[1005];
int mark[100005];
int cost[100005];
void bfs(){
	memset(cost,-1,sizeof(cost));
	queue<int> q;
	REP(i,n) if(mark[i]){
		cost[i]=0;
		q.push(i);
	}
	while(!q.empty()){
		int cur=q.front();q.pop();
		REP(i,g[cur].size()){
			int to=g[cur][i];
			if(cost[to]!=-1) continue;
			cost[to]=cost[cur]+1;
			q.push(to);
		}
	}
}
int par[20][100005];
int dep[100005];
void dfs(int v,int p,int d){
	par[0][v]=p;
	dep[v]=d;
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		dfs(to,v,d+1);
	}
}

int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	int dif=dep[b]-dep[a];
	REP(i,20) if(dif>>i&1) b=par[i][b];
	if(a==b) return a;
	for(int i=19;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];b=par[i][b];
	}
	return par[0][a];
}

int getdist(int a,int b){
	return dep[a]+dep[b]-dep[lca(a,b)]*2;
}
int solve(int v,int m){
	int res=cost[v];
	REP(i,m){
		res=min(res,getdist(newvs[i],v));
	}
	return res;
}

int main(){
	cin>>n>>m;
	REP(i,n-1){
		int a,b;cin>>a>>b;--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	dfs(0,-1,0);
	REP(i,19) REP(j,n){
		if(par[i][j]==-1) par[i+1][j]=-1;
		else par[i+1][j]=par[i][par[i][j]];
	}

	mark[0]=1;
	for(int st=0;st<m;st+=B){
		int cnt=0;
		bfs();
		for(int i=st;i<min(m,st+B);++i){
			int t,v;scanf("%d%d",&t,&v);--v;
			if(t==1) newvs[cnt++]=v,mark[v]=1;
			else printf("%d\n",solve(v,cnt));
		}
	}



	return 0;
}