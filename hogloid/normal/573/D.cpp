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
int match[30005];
struct segtree{
  int n;
  int n_;
  lint w[30005],h[30005];

  pi off[4]={mp(-1,-1),mp(0,0),mp(0,1),mp(1,0)};
  lint val[70000][4][4];

  void con(int i,int l,int r,int A,int B){
    if(~A){
      if(!(l<=A && A<r) && !(l<=B && B<r)) return;
    }
    int l2=min(l,n_),r2=min(r,n_);
    if(r2-l2==2){
      memset(val[i],-1,sizeof(val[i]));
      if(match[l]!=l && match[l+1]!=l+1)
        chmax(val[i][0][0],w[l]*h[l]+w[l+1]*h[l+1]);
      if(match[l]!=l+1 && match[l+1]!=l)
        chmax(val[i][0][0],w[l]*h[l+1]+w[l+1]*h[l]);

      if(match[l]!=l+1){
        chmax(val[i][3][0],w[l]*h[l+1]);
        chmax(val[i][0][2],w[l]*h[l+1]);
      }
      if(match[l+1]!=l){
        chmax(val[i][2][0],w[l+1]*h[l]);
        chmax(val[i][0][3],w[l+1]*h[l]);
      }
      if(match[l]!=l){
        chmax(val[i][0][1],w[l]*h[l]);
      }
      if(match[l+1]!=l+1){
        chmax(val[i][1][0],w[l+1]*h[l+1]);
      }
      {
        chmax(val[i][2][2],0ll);
        chmax(val[i][3][3],0ll);
        chmax(val[i][1][1],0ll);
      }
    dump(l);dump(r);
    REP(k,4) debug(val[i][k],val[i][k]+4);
      return;
    }
    if(r2-l2==1){
      memset(val[i],-1,sizeof(val[i]));
      if(match[l]!=l)
        chmax(val[i][0][0],w[l]*h[l]);
      chmax(val[i][1][0],0ll);
    dump(l);dump(r);
    REP(k,4) debug(val[i][k],val[i][k]+4);
      return;
    }
    if(r2-l2==0){
      memset(val[i],-1,sizeof(val[i]));
      val[i][0][0]=0;
      return;
    }

    int md=(l+r)>>1;
    con(i*2+1,l,md,A,B);
    con(i*2+2,md,r,A,B);

    memset(val[i],-1,sizeof(val[i]));
    REP(x,4) REP(y,4) if(~val[i*2+1][x][y]) REP(z,4) REP(w2,4) if(~val[i*2+2][z][w2]){
      lint sum=val[i*2+1][x][y]+val[i*2+2][z][w2];
      if((y>0) ^ (z>0)) continue;
      if(y==0) chmax(val[i][x][w2],sum);
      else{
        int t1=md-1-off[y].fr,t2=md+off[z].fr,b1=md-1-off[y].sc,b2=md+off[z].sc;
        if(match[t1]!=b2 && match[t2]!=b1)
          chmax(val[i][x][w2],sum+w[t1]*h[b2]+w[t2]*h[b1]);
      }
    }
    dump(l);dump(r);
    REP(k,4) debug(val[i][k],val[i][k]+4);
  }
  void init(int n__){
    n=1;
    n_=n__;
    while(n<n_) n<<=1;
    dump(n);

    con(0,0,n,-1,-1);
  }
  void swap2(int a,int b){
    swap(match[a],match[b]);
    debug(match,match+n_);
    con(0,0,n,a,b);
  }
  lint query(){
    return val[0][0][0];
  }
};

int n,q;
segtree seg;

  pi w2[30005],h2[30005];
  int pos[30005],pos2[30005];
int main(){
  cin>>n>>q;
  REP(i,n) cin>>w2[i].fr,w2[i].sc=i;
  REP(i,n) cin>>h2[i].fr,h2[i].sc=i;

  sort(w2,w2+n);
  sort(h2,h2+n);

  REP(i,n) pos[h2[i].sc]=i,pos2[w2[i].sc]=i;
  REP(i,n){
    match[i]=pos[w2[i].sc];
    seg.w[i]=w2[i].fr;
    seg.h[i]=h2[i].fr;
  }

  seg.init(n);
  debug(match,match+n);
  debug(pos2,pos2+n);
  REP(i,q){
    int a,b;cin>>a>>b;--a;--b;
    a=pos2[a],b=pos2[b];
    seg.swap2(a,b);

    cout<<seg.query()<<endl;
  }
  return 0;
}