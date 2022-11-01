#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
using namespace std;
static const int INF =500000000; 
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;
int src,sink;
static const int MAX_SIZE=55*205+2;



struct edge{
	int to,cap,rev;
	edge(int st,int sc,int sr){
		to=st;cap=sc;rev=sr;
	}
};
vector<edge> g[MAX_SIZE];
int rankk[MAX_SIZE],seen[MAX_SIZE];
void add_edge(int from,int to,int cap){
	g[from].pb(edge(to,cap,g[to].size()));
	g[to].pb(edge(from,0,g[from].size()-1));
}
void bfs(int v){
	memset(rankk,-1,sizeof(rankk));
	rankk[v]=0;
	queue<int>q;q.push(v);
	while(!q.empty()){
		int cur=q.front();q.pop();
		REP(i,g[cur].size()){
			edge& e=g[cur][i];
			if(e.cap>0 && rankk[e.to]==-1){
				rankk[e.to]=rankk[cur]+1;
				q.push(e.to);
			}
		}
	}
}
int dfs(int v,int f){
	if(v==sink) return f;
	for(int& i=seen[v];i<g[v].size();++i){
		edge& e=g[v][i];
		if(e.cap>0 && rankk[e.to]>rankk[v]){
			int d=dfs(e.to,min(e.cap,f));
			if(d>0){
				e.cap-=d;
				g[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}
int max_flow(int s,int t){
	src=s;sink=t;
	int flow=0;
	while(1){
		bfs(src);
		if(rankk[sink]==-1) return flow;
		int f;
		memset(seen,0,sizeof(seen));
		while((f=dfs(src,INF))>0){
			flow+=f;
		}
	}
}static const int LARGE=300000;

int n,m;
int A[55],B[55],C[55],L[55],R[55];
int LEN=202;
vector<pi> gr[55];

int eval(int i,int j){
	return A[i]*j*j+B[i]*j+C[i];
}

int main(){
	cin>>n>>m;
	REP(i,n){
		cin>>A[i]>>B[i]>>C[i];
	}
	REP(i,n) cin>>L[i]>>R[i];
	
	REP(i,m){
		int u,v,d;cin>>u>>v>>d;
		--u;--v;
		gr[u].pb(mp(v,-d));
	}

	int S=n*LEN,T=S+1;
	REP(i,n){
		add_edge(S,i*LEN+L[i]+100,INF);
		for(int j=L[i];j<=R[i];++j){
			add_edge(i*LEN+j+100,i*LEN+j+101,LARGE-eval(i,j));
		}
		for(int j=L[i]-1;j<=R[i];++j){
			REP(k,gr[i].size()){
				int to=gr[i][k].fr,st=max(L[to]-1,j+gr[i][k].sc);
				if(st<=R[to]) add_edge(i*LEN+j+101,to*LEN+st+101,INF);
			}
		}

		add_edge(i*LEN+R[i]+101,T,INF);
	}

	int res=max_flow(S,T);
	int ans=LARGE*n-res;

	cout<<ans<<endl;






	return 0;
}