#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
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
int m,n,d;
vector<int> g[100005];
int mark[100005];

pi most[100005],sec[100005];

void ins(int v,int val,int chil){
	if(most[v].fr<val){
		if(most[v].sc!=chil){
			sec[v]=most[v];
			most[v]=mp(val,chil);
		}else most[v]=mp(val,chil);
	}else if(sec[v].fr<val && most[v].sc!=chil){
		sec[v]=mp(val,chil);
	}
}

void prep(int v,int p){
	most[v]=sec[v]=mp(-INF,-1);
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		prep(to,v);

		ins(v,most[to].fr+1,to);
		ins(v,sec[to].fr+1,to);
	}
	if(mark[v]) ins(v,0,-1);
}

int dist[100005];
void dfs(int v,int p){
	REP(i,g[v].size()){
		int to=g[v][i];
		if(to==p) continue;
		
		dist[to]=max(dist[to],dist[v]+1);
		if(to==most[v].sc) dist[to]=max(dist[to],sec[v].fr+1);
		else dist[to]=max(dist[to],most[v].fr+1);
		dfs(to,v);
	}
}

int main(){
	cin>>n>>m>>d;
	REP(i,m){
		int a;cin>>a;
		--a;
		mark[a]=1;
	}
	REP(i,n-1){
		int a,b;scanf("%d%d",&a,&b);--a;--b;
		g[a].pb(b);
		g[b].pb(a);
	}
	int root=0;
	prep(root,-1);
	
	REP(i,n) dist[i]=-INF;
	dfs(root,-1);

	REP(i,n) dist[i]=max(dist[i],most[i].fr);
	
	int res=0;
	REP(i,n) if(dist[i]<=d) ++res;
	cout<<res<<endl;
	return 0;
}