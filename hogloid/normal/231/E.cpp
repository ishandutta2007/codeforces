#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<stack>
#include<vector>
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
const lint mod=1e9+7;
int n,m;
vector<int> g[100005],g2[100005];
int order[100005],low[100005],cnt;
stack<int> cur;
int group[100005],gcnt,belong[100005];
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
int par[20][100005];
int dep[100005],dep2[100005];
pair<pi,pi> es[100005];
int ecnt;
void dfs2(int v,int p,int d=0,int d2=0){
	par[0][v]=p;
	dep[v]=d;
	d2+=(belong[v]>1);
	dep2[v]=d2;
	REP(i,g2[v].size()){
		int to=g2[v][i];
		if(to==p || to==v) continue;
		dfs2(to,v,d+1,d2);
	}
}
int lca(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	int dif=dep[b]-dep[a];
	REP(i,20) if(dif>>i&1) b=par[i][b];
	if(a==b) return a;
	for(int i=19;i>=0;--i) if(par[i][a]!=par[i][b]){
		a=par[i][a];
		b=par[i][b];
	}
	return par[0][a];
}
int parentK(int a,int k){
	int res=a;
	REP(i,20) if(k>>i&1) res=par[i][res];
	return res;
}
int mpow(int k){
	lint res=1;
	lint a=2;
	while(k){
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&m);
	REP(i,m){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);g[b].pb(a);
	}
	memset(order,-1,sizeof(order));
	dfs(0,-1);
	REP(i,n) ++belong[group[i]];
	
	REP(i,n) REP(j,g[i].size()){
		int to=group[g[i][j]];
		g2[group[i]].pb(to);
		g2[to].pb(group[i]);

		es[ecnt++]=mp(mp(group[i],to),mp(i,g[i][j]));
	}
	sort(es,es+ecnt);
	REP(i,gcnt) sort(ALL(g2[i])),g2[i].erase(unique(ALL(g2[i])),g2[i].end());

	dfs2(0,-1);
	REP(i,19) REP(j,gcnt){
		if(par[i][j]==-1) par[i+1][j]=par[i][j];
		else par[i+1][j]=par[i][par[i][j]];
	}

	int q;scanf("%d",&q);
	REP(hoge,q){
		int a,b;scanf("%d%d",&a,&b);--a;--b;

		int A=group[a],B=group[b],L=lca(A,B);
		if(dep[A]>dep[B]) swap(A,B);
		int res=0;
		pi critic;
		if(A==B){
			if(a==b) res=0;
			else res=1;
		}else if(A==L){
			res=dep2[A]+dep2[B]-dep2[L]*2+(belong[L]>1);
		}else{
			res=dep2[A]+dep2[B]-dep2[L]*2+(belong[L]>1);
		}

		printf("%d\n",mpow(res));
	}
	return 0;
}