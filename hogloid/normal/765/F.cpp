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

const int INF=1e9+100;

int ar[100005];

struct segtree{
  int val[400005];
  int n;
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2) val[i]=INF;
  }
  void set(int k,int a){
    k+=n-1;
    chmin(val[k],a);
    while(k>0){
      k=(k-1)/2;
      chmin(val[k],a);
    }
  }
  int query(int a,int b,int i,int l,int r){
    if(a<=l && r<=b) return val[i];
    if(b<=l || r<=a) return INF;
    int md=(l+r)>>1;
    return min(query(a,b,i*2+1,l,md),query(a,b,i*2+2,md,r));
  }
};

segtree seg1,seg2;
int n;
int zip[100005],zn;
int geth(int x){
  return lower_bound(zip,zip+zn,x)-zip;
}
pi que[300005];
vector<pi> query[100005];
int ans[300005];
int main(){
  cin>>n;
  REP(i,n) scanf("%d",&ar[i]),zip[i]=ar[i];
  int q;cin>>q;
  REP(i,q){
    int l,r;scanf("%d%d",&l,&r);--l;--r;
    que[i]={l,r};
  }

  sort(zip,zip+n);
  zn=unique(zip,zip+n)-zip;
  REP(i,q) ans[i]=INF;

  REP(_,2){
    prl;
    REP(i,n) query[i].clear();

    REP(i,q){
      query[que[i].sc].pb({que[i].fr,i});
    }
    seg1.init(n);
    seg2.init(zn);
    REP(i,n){
      int top=INF;
      int hei_i=geth(ar[i]);
      while(top>ar[i]){
        int lb=hei_i,ub=geth(top);//[lb...ub)
        int j=-seg2.query(lb,ub,0,0,seg2.n);
        if(j<0) break;
        seg1.set(j,ar[j]-ar[i]);
        int dif=ar[j]-ar[i];
        top=ar[i]+(dif+1)/2;
      }
      seg2.set(hei_i,-i);
      for(auto e:query[i]){
        chmin(ans[e.sc],seg1.query(e.fr,i+1,0,0,seg1.n));
      }
    }
    reverse(ar,ar+n);
    REP(i,q){
      que[i].fr=n-1-que[i].fr;
      que[i].sc=n-1-que[i].sc;
      swap(que[i].fr,que[i].sc);
    }
  }
  REP(i,q) printf("%d\n",ans[i]);
  return 0;
}