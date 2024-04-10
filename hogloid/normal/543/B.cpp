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
int n,m;
vector<int> g[3005];
int cost[3005][3005];
void bfs(int* cost,int S){
  REP(i,n) cost[i]=INF;
  queue<int> q;q.push(S);
  cost[S]=0;
  while(!q.empty()){
    int cur=q.front();q.pop();
    for(auto to:g[cur]){
      if(cost[to]==INF){
        cost[to]=cost[cur]+1;
        q.push(to);
      }
    }
  }
}
int main(){
  cin>>n>>m;
  REP(i,m){
    int a,b;cin>>a>>b;--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  int vs1[2],vs2[2];
  int l1,l2;
  cin>>vs1[0]>>vs1[1]>>l1>>vs2[0]>>vs2[1]>>l2;
  --vs1[0];--vs1[1];
  --vs2[0];--vs2[1];

  REP(i,n) bfs(cost[i],i);
  if(cost[vs1[0]][vs1[1]]>l1 || cost[vs2[0]][vs2[1]]>l2){
    puts("-1");
    return 0;
  }

  int res=cost[vs1[0]][vs1[1]]+cost[vs2[0]][vs2[1]];
  REP(i,n) REP(j,n){
    REP(t,2) REP(t2,2) if(cost[vs1[t]][i]+cost[i][j]+cost[j][vs1[1-t]]<=l1 &&
                          cost[vs2[t2]][i]+cost[i][j]+cost[j][vs2[1-t2]]<=l2){
      chmin(res,cost[vs1[t]][i]+cost[vs2[t2]][i]+cost[i][j]+cost[j][vs1[1-t]]+cost[j][vs2[1-t2]]);
    }
  }
  cout<<m-res<<endl;
  return 0;
}