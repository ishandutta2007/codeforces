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

//const int INF=5e8;
int n,m;
vector<int> g[1005];
int col[1005];

int cost[1005],longest[1005];
void dfs(int v,int c){
  col[v]=c;
  for(auto to:g[v]){
    if(col[to]==-1){
      dfs(to,1-c);
    }else if(col[to]!=1-c){
      puts("-1");
      exit(0);
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
  memset(col,-1,sizeof(col));
  REP(i,n) if(col[i]==-1){
    dfs(i,0);
  }
  memset(longest,-1,sizeof(longest));
  REP(i,n){
    queue<int> q;q.push(i);
    memset(cost,-1,sizeof(cost));
    cost[i]=0;
    while(!q.empty()){
      int cur=q.front();q.pop();
      for(auto to:g[cur]){
        if(cost[to]==-1){
          cost[to]=cost[cur]+1;
          q.push(to);
        }
      }
    }
    int id=-1;
    REP(j,n) if(cost[j]!=-1) id=j;
    chmax(longest[id],*max_element(cost,cost+n));
  }
  int res=0;
  REP(i,n) if(longest[i]>=0){
    res+=longest[i];
  }
  cout<<res<<endl;
  return 0;
}