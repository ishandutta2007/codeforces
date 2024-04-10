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
#define dumpR(x) cerr<<"\x1b[31m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpY(x) cerr<<"\x1b[33m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
#define dumpG(x) cerr<<"\x1b[32m"<<#x<<" = " <<(x)<<"\x1b[39m"<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define dumpR(x) ;
#define dumpY(x) ;
#define dumpG(x) ;
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
struct segtree{
  struct uf{
    static const int MAXN=11;
    int par[MAXN];
    void init(){
      REP(i,MAXN) par[i]=i;
    }
    void unite(int a,int b){
      REP(i,MAXN) if(par[i]==b) par[i]=a;
    }
  };
  int n;

  uf root[400005];
  lint sum[400005][10];
  void init(int n_,int* ar){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2){
      root[i].init();
    }
    REP(i,n_){
      int ex=1;
      int tmp=ar[i];
      while(tmp){
        sum[i+n-1][tmp%10]+=ex;
        tmp/=10;
        ex*=10;
      }
    }
    for(int i=n-2;i>=0;--i){
      REP(j,10) sum[i][j]=sum[i*2+1][j]+sum[i*2+2][j];
    }
  }
  void push(int id){
    lint tmp1[10]={0},tmp2[10]={0};
    REP(i,10){
      int x=root[id].par[i];
      tmp1[x]+=sum[id*2+1][i];
      tmp2[x]+=sum[id*2+2][i];
    }
    auto fix=[&](int& x){
      x=root[id].par[x];
    };
    REP(i,10){
      fix(root[id*2+2].par[i]);
      fix(root[id*2+1].par[i]);
    }
    REP(i,10){
      sum[id*2+1][i]=tmp1[i];
      sum[id*2+2][i]=tmp2[i];
    }
    root[id].init();
  }
  lint query(int a,int b,int i,int l,int r){
    if(a<=l && r<=b){
      lint res=0;
      REP(j,10) res+=sum[i][j]*j;
      return res;
    }
    if(b<=l || r<=a) return 0;
    int md=(l+r)>>1;
    push(i);
    return query(a,b,i*2+1,l,md)+query(a,b,i*2+2,md,r);
  }
  void merge(int a,int b,int i,int l,int r,int x,int y){
    if(a<=l && r<=b){
      if(x!=y){
        root[i].unite(x,y);
        sum[i][x]+=sum[i][y];
        sum[i][y]=0;
      }
      return;
    }
    if(b<=l || r<=a) return;
    int md=(l+r)>>1;
    push(i);
    merge(a,b,i*2+1,l,md,x,y);
    merge(a,b,i*2+2,md,r,x,y);
    REP(j,10) sum[i][j]=sum[i*2+1][j]+sum[i*2+2][j];
  }
};
segtree seg;

int n,q;
int ar[100005];
int main(){
  cin>>n>>q;
  REP(i,n) scanf("%d",&ar[i]);
  seg.init(n,ar);
  REP(i,q){
    int t,l,r;scanf("%d%d%d",&t,&l,&r);--l;
    if(t==1){
      int x,y;scanf("%d%d",&x,&y);
      seg.merge(l,r,0,0,seg.n,y,x);
    }else{
      lint res=seg.query(l,r,0,0,seg.n);
      printL(res);
      puts("");
    }
  }
  return 0;
}