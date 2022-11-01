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

int n;
set<int> edge[1005];

vector<pi> ans;
vector<pi> res;

bool flag;


void flip(int a,int b){
  auto it=edge[b].lower_bound(a),it2=edge[b].lower_bound(a);
  if(it==edge[b].end()) it=edge[b].begin();
  ++it;
  if(it==edge[b].end()) it=edge[b].begin();

  if(it2==edge[b].begin()) it2=edge[b].end();
  --it2;

  int c=*it,d=*it2;
  edge[a].erase(b);
  edge[b].erase(a);

  edge[c].insert(d);
  edge[d].insert(c);

  if(flag) res.pb(mp(c,d));
  else res.pb(mp(a,b));
}
void rec(int l,int r){
  dump(l);dump(r);
  while(l+1<r && edge[0].count(l+1)) ++l;
  while(l+1<r && edge[0].count(r-2)) --r;

  if(r-l<2) return;

  auto it=edge[0].lower_bound(l+1);
  if(it==edge[0].end() || *it>=r-1){
    flip(l,r-1);
  }
  it=edge[0].lower_bound(l+1);
  rec(l,(*it)+1);
  rec(*it,r);
}

void solve(){
  REP(i,n) edge[i].clear();

  REP(i,n-3){
    int a,b;cin>>a>>b;--a;--b;
    edge[a].insert(b);
    edge[b].insert(a);
  }

  REP(i,n){
    edge[i].insert((i+1)%n);
    edge[(i+1)%n].insert(i);
  }

  res.clear();
  rec(1,n);
  
  debug(ALL(res));
}
int main(){
  cin>>n;

  vector<pi> A,B;
  solve();
  A=res;
  flag=true;
  solve();
  B=res;
  reverse(ALL(B));

  A.insert(A.end(),ALL(B));

  cout<<A.size()<<endl;
  for(auto e:A) printf("%d %d\n",e.fr+1,e.sc+1);
  return 0;
}