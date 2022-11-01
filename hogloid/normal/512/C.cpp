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

const int INF=5e8;
int src,sink;
static const int MAX_SIZE=405;


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
}

int n;
int ar[205];

bool isprime(int a){
  for(int i=2;i*i<=a;++i) if(a%i==0) return false;
  return true;
}


vector<int> nxt[205];
int done[205];
int main(){
  cin>>n;
  REP(i,n) cin>>ar[i];

  int S=n,T=S+1;
  REP(i,n) REP(j,n) if((ar[i]%2==0 && ar[j]%2==1) && isprime(ar[i]+ar[j])){
    add_edge(i,j,1);
  }
  REP(i,n) if(!(ar[i]&1)) add_edge(S,i,2);
  REP(i,n) if(ar[i]&1) add_edge(i,T,2);

  int mxf=max_flow(S,T);

  if(mxf<n) puts("Impossible");
  else{
    REP(i,n) if(!(ar[i]&1)){
      for(auto e:g[i]){
        if(e.to<n && e.cap==0){
          nxt[i].pb(e.to);
          nxt[e.to].pb(i);
        }
      }
    }

    
    vector<vector<int> >res;
    REP(i,n) if(!done[i]){
      int cur=i;

      vector<int> loop;
      while(!done[cur]){
        loop.pb(cur);
        done[cur]=1;
        for(auto to:nxt[cur]){
          if(!done[to]){
            cur=to;
            break;
          }
        }
      }
      res.pb(loop);
    }
    cout<<res.size()<<endl;
    REP(i,res.size()){
      cout<<res[i].size();
      REP(j,res[i].size()) assert(isprime(ar[res[i][j]]+ar[res[i][(j+1)%res[i].size()]]));

      for(auto v:res[i]) printf(" %d",v+1);
      putchar('\n');
    }
  }
  return 0;
}