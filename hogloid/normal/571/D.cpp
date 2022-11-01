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
typedef pair<int,lint> pi;

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
struct uf_p{
  static const int MAXN=500005;
  int par[MAXN];
  int size[MAXN];
  int mdate[MAXN];
  int raid[MAXN];
  void init(){
    memset(par,-1,sizeof(par));
    REP(i,MAXN){
      size[i]=1;
      mdate[i]=-1;
      raid[i]=-1;
    }
  }
  int root(int a){
    if(par[a]==-1) return a;
    return root(par[a]);
  }
  void unite(int a,int b,int d){
    a=root(a);b=root(b);
    if(a==b) return;
    if(size[a]<size[b]) swap(a,b);

    par[b]=a;
    size[a]+=size[b];
    mdate[b]=d;
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
  void cond(int a,int v){
    a=root(a);
    raid[a]=v;
  }
  int lastraid(int a){
    int res=-1;
    int least=-1;
    while(a!=-1){
      if(raid[a]>=least) chmax(res,raid[a]);
      chmax(least,mdate[a]);
      a=par[a];
    }
    return res;
  }
};

uf_p police;

struct uf_u{
  static const int MAXN=500005;
  int par[MAXN];
  int size[MAXN];
  int mdate[MAXN];
  vector<pi> sum[MAXN];
  //(date,val);
  lint sum2[MAXN];
  void init(){
    memset(par,-1,sizeof(par));
    REP(i,MAXN){
      size[i]=1;
      mdate[i]=-1;
      sum[i].clear();
      sum[i].pb(mp(-2,0));
      sum2[i]=0;
    }
  }
  int root(int a){
    if(par[a]==-1) return a;
    return root(par[a]);
  }
  void unite(int a,int b,int d){
    a=root(a);b=root(b);
    if(a==b) return;
    if(size[a]<size[b]) swap(a,b);

    par[b]=a;
    size[a]+=size[b];
    mdate[b]=d;
  }
  bool same(int a,int b){
    return root(a)==root(b);
  }
  void mvin(int a,int d){
    a=root(a);
    sum2[a]+=size[a];
    sum[a].pb(mp(d,sum2[a]));
  }
  lint getfrom(int a,int from){
    lint res=0;
    while(~a){
      int p=lower_bound(ALL(sum[a]),mp(from,-1ll))-sum[a].begin();--p;
      dump(p);dump(sum2[a]);
      res+=sum2[a]-sum[a][p].sc;
      chmax(from,mdate[a]);
      a=par[a];
    }
    return res;
  }
};
uf_u univ;

int n,m;

int main(){
  police.init();
  univ.init();
  cin>>n>>m;
  REP(i,m){
    char s[5];int a,b;
    scanf("%s%d",s,&a);--a;
    if(s[0]=='U'){
      scanf("%d",&b);--b;
      univ.unite(a,b,i);
    }else if(s[0]=='M'){
      scanf("%d",&b);--b;
      police.unite(a,b,i);
    }else if(s[0]=='A'){
      univ.mvin(a,i);
    }else if(s[0]=='Z'){
      police.cond(a,i);
    }else{
      int p=police.lastraid(a);
      dump(p);
      lint res=univ.getfrom(a,p);
      printf("%lld\n",res);
    }
  }

  return 0;
}