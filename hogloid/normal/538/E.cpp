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

int n;
vector<int> g[200005];
int rec(int v,int d=0){
  if(g[v].size()==0) return 1;
  int res=0;
  if(d%2==0) res=INF;
  for(auto to:g[v]){
    if(d%2==0) chmin(res,rec(to,d+1));
    else res+=rec(to,d+1);
  }
  return res;
}

int rec2(int v,int d=0){
  if(g[v].size()==0) return 1;

  int res=0;
  if(d%2) res=INF;
  for(auto to:g[v]){
    if(d%2==0) res+=rec2(to,d+1);
    else chmin(res,rec2(to,d+1));
  }
  return res;
}

int leaf=0;
int main(){
  cin>>n;
  REP(i,n-1){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
  }

  REP(i,n) if(g[i].size()==0) ++leaf;
  dump(leaf);

  int res1=leaf-rec(0)+1,res2=rec2(0);
  cout<<res1<<endl;
  cout<<res2<<endl;

  return 0;
}