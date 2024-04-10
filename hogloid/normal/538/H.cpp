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

const int INF=1e9+10;
int t,T;
int n,m;
pi range[100005];
vector<int> g[100005];

void FAIL(){
  puts("IMPOSSIBLE");
  exit(0);
}
int col[100005];
pi inter[2];
vector<int> vs[2];
void dfs(int v,int c){
  col[v]=c;
  vs[c].pb(v);
  chmax(inter[c].fr,range[v].fr);
  chmin(inter[c].sc,range[v].sc);
  for(auto to:g[v]){
    if(col[to]==-1){
      dfs(to,1-c);
    }else if(col[to]!=1-c) FAIL();
  }
}
vector<pi> all;
vector<pair<pi,int> >alone;
typedef vector<int> vi;
vector<pair<pair<pi,pi>,pair<vi,vi> > >twin;
//((range1,range2),(set1,set2))
int res[100005];
void solve(int L,int R){
  if(L<0) FAIL();
  for(auto e:alone){
    if(e.fr.fr<=L && L<=e.fr.sc){
      res[e.sc]=0;
    }else if(e.fr.fr<=R && R<=e.fr.sc){
      res[e.sc]=1;
    }else FAIL();
  }
  for(const auto& e:twin){
    pi r1=e.fr.fr,r2=e.fr.sc;
    const vi& s1=e.sc.fr,&s2=e.sc.sc;
    if(r1.fr<=L && L<=r1.sc && r2.fr<=R && R<=r2.sc){
      for(auto v:s1) res[v]=0;
      for(auto v:s2) res[v]=1;
    }else if(r2.fr<=L && L<=r2.sc && r1.fr<=R && R<=r1.sc){
      for(auto v:s1) res[v]=1;
      for(auto v:s2) res[v]=0;
    }else FAIL();
  }
  puts("POSSIBLE");
  printf("%d %d\n",L,R);
  REP(i,n) putchar('1'+res[i]);
  putchar('\n');
}

int main(){
  cin>>t>>T;
  cin>>n>>m;
  REP(i,n){
    scanf("%d%d",&range[i].fr,&range[i].sc);
  }
  REP(hoge,m){
    int a,b;scanf("%d%d",&a,&b);--a;--b;
    g[a].pb(b);
    g[b].pb(a);
  }

  memset(col,-1,sizeof(col));
  REP(i,n) if(col[i]==-1){
    inter[0]=inter[1]=mp(-INF,INF);
    vs[0].clear();vs[1].clear();
    dfs(i,0);
    if(inter[1].fr>=0){
      twin.pb(mp(mp(inter[0],inter[1]),mp(vs[0],vs[1])));
      /*if(inter[1].fr<inter[0].fr) swap(inter[0],inter[1]);
      if(inter[1].sc<=inter[0].sc){//0 include 1
        t2.pb(mp(inter[0],inter[1]));
      }else{
        t1.pb(mp(inter[0],inter[1]));
      }*/
      all.pb(inter[1]);
    }else{
      alone.pb(mp(inter[0],i));
    }
    all.pb(inter[0]);
  }
  {
    int Rmin=INF,Lmax=-INF;
    for(auto e:all){
      chmin(Rmin,e.sc);
      chmax(Lmax,e.fr);
    }
    if(Rmin<Lmax){
      if(Rmin+Lmax<t){
        solve(Rmin,t-Rmin);
      }else if(Rmin+Lmax>T){
        solve(T-Lmax,Lmax);
      }else{
        solve(Rmin,Lmax);
      }
    }else{
      int lb=Lmax*2,ub=Rmin*2;
      if(max(lb,t)<=min(ub,T)){
        solve(max(lb,t)/2,(max(lb,t)+1)/2);
      }else if(ub<=t){
        solve(Rmin,t-Rmin);
      }else{
        solve(T-Lmax,Lmax);
      }
    }
  }
/*  for(auto e:all){
    chmin(A.sc,e.sc);
    chamx(B.fr,e.fr);
  }
  for(auto e:all){
    if(e.sc<B.fr){
      chmax(A.fr,e.fr);
    }
    if(A.sc<e.fr){
      chmin(B.sc,e.sc);
    }
  }
  for(auto e:t2){
    pi lrg=e.fr,sml=e.sc;
    if(sml.fr<=A.sc && B.fr<=sml.sc){
      chmax(A.fr,lrg.fr);
      chmin(B.sc,lrg.sc);
    }else if(sml.sc<B.fr){
      getprod(B,lrg);
      getprod(A,sml);
    }else{
      getprod(A,lrg);
      getprod(B,sml);
    }
  }*/


  return 0;
}