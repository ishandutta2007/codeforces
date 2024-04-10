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
vector<pair<pi,int> > g[30005];

int pot[30005];
int main(){
  cin>>n;
  REP(i,n*4){
    int a,b,c;scanf("%d%d%d",&a,&b,&c);--a;--b;--c;
    g[a].pb(mp(mp(b,c),i));
  }
  vector<int> res;
  REP(i,n) pot[i]=8;

  set<int> less9;
  REP(i,n) less9.insert(i);
  REP(hoge,n*4){
    auto it=less9.begin();
    while(it!=less9.end()){
      int v=*it;
      if(!g[v].empty()){
        int b=g[v].back().fr.fr,c=g[v].back().fr.sc;
        res.pb(g[v].back().sc);
        ++pot[v];
        --pot[b];
        --pot[c];
        if(pot[v]==9) less9.erase(it);
        if(pot[b]<9) less9.insert(b);
        if(pot[c]<9) less9.insert(c);
        g[v].pop_back();
        break;
      }else{
        less9.erase(it++);
      }
    }
    if(it==less9.end()){
      while(1){};
    }
  }
  reverse(ALL(res));
  puts("YES");
  REP(i,n*4) printf("%d\n",res[i]+1);
  return 0;
}