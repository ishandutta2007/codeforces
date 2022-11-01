#include<bits/stdc++.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifndef ONLINE_JUDGE
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }
typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

lint readL(){
  lint res;
#ifdef ONLINE_JUDGE
  scanf("%I64d",&res);
#else
  scanf("%lld",&res);
#endif
  return res;
}
void printL(lint res){
#ifdef ONLINE_JUDGE
  printf("%I64d",res);
#else
  printf("%lld",res);
#endif
}
int src,sink;
static const int MAX_SIZE=2005;


struct edge{
	int to,cap,rev;
	edge(int st,int sc,int sr){
		to=st;cap=sc;rev=sr;
	}
};


const int INF=5e8;
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
}
int h,w;

int n,m;

char buf[25][25];
int mat[500][500];

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int N;
int cnt[2];
pair<pi,int> ar[2][500];
void read_(int ind){
  int a,b,c;cin>>a>>b>>c;--a;--b;
  ar[ind][cnt[ind]]=mp(mp(a,b),c);
  ++cnt[ind];
}

bool check(lint time){
  int S=2*(n+N),T=S+1;;
  REP(i,T+1) g[i].clear();
  REP(i,n){
    int p=ar[0][i].fr.fr*w+ar[0][i].fr.sc;
    add_edge(S,i,1);
    REP(j,N) if(mat[p][j]<INF){
      lint cost=mat[p][j]*(lint)ar[0][i].sc;
      if(cost<=time) add_edge(i,n+j,1);
    }
  }
  REP(j,N) add_edge(n+j,n+N+j,1);

  REP(i,n){
    int p=ar[1][i].fr.fr*w+ar[1][i].fr.sc;
    add_edge(i+n+N+N,T,1);
    REP(j,N) if(mat[p][j]<INF){
      lint cost=mat[p][j]*(lint)ar[1][i].sc;
      if(cost<=time) add_edge(n+N+j,i+n+N+N,1);
    }
  }
  if(max_flow(S,T)==n) return true;
  return false;
}


int main(){
  cin>>h>>w>>n>>m;
  REP(i,h) scanf("%s",buf[i]);

  N=h*w;
  REP(i,N) REP(j,N) mat[i][j]=INF;
  REP(i,N) mat[i][i]=0;

  REP(i,h) REP(j,w) if(buf[i][j]=='.'){
    int c1=i*w+j;
    REP(d,4){
      int px=j+dx[d],py=i+dy[d];
      if(px<0 || py<0 || px>=w || py>=h || buf[py][px]=='#') continue;
      int c2=py*w+px;
      mat[c1][c2]=mat[c2][c1]=1;
    }
  }

  REP(i,N) REP(j,N) REP(k,N) chmin(mat[j][k],mat[j][i]+mat[i][k]);

  if(abs(n-m)>1 || n==m){
    puts("-1");
    return 0;
  }
  if(n>m) read_(1);
  else read_(0);

  REP(i,n) read_(0);
  REP(i,m) read_(1);

  n=m=max(n,m);

  lint MX=1e17;
  lint lb=-1,ub=MX;
  while(ub-lb>1){
    lint md=(lb+ub)>>1;
    if(check(md)) ub=md;
    else lb=md;
  }

  if(ub==MX) ub=-1;
  cout<<ub<<endl;
  return 0;
}