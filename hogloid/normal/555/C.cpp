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

struct segtree{
  int val[1600005];
  int n;
  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n*2) val[i]=0;
  }
  void set(int a,int b,int i,int l,int r,int k){
    if(a<=l && r<=b){
      chmax(val[i],k);
      return;
    }
    if(b<=l || r<=a) return;
    int md=(l+r)>>1;
    set(a,b,i*2+1,l,md,k);
    set(a,b,i*2+2,md,r,k);
  }
  int query(int k){
    k+=n-1;
    int res=val[k];
    while(k>0){
      k=(k-1)/2;
      chmax(res,val[k]);
    }
    return res;
  }
};
segtree segX,segY;

int n,q;


pair<pi,int> event[200005];
int zip[400005];

set<pi> eaten;
int main(){
  cin>>n>>q;


  char tmp[5];
  REP(i,q){
    int x,y;
    scanf("%d%d%s",&x,&y,tmp);
    --x;--y;

    int c;
    if(tmp[0]=='U') c=0;
    else c=1;

    event[i]=mp(mp(y,x),c);
    zip[i]=y;
    zip[i+q]=x;
  }

  int zn=2*q;
  zip[zn++]=-1;
  sort(zip,zip+zn);

  zn=unique(zip,zip+zn)-zip;

  segX.init(zn);
  segY.init(zn);

  REP(i,q){
    int x=event[i].fr.sc,y=event[i].fr.fr,c=event[i].sc;

    int X=lower_bound(zip,zip+zn,x)-zip,Y=lower_bound(zip,zip+zn,y)-zip;

    int res;
    if(eaten.count(mp(x,y))){
      res=0;
    }else{
      if(c==0){
        int till=segX.query(X);
        res=y-zip[till];

        segY.set(till,Y+1,0,0,segY.n,X);
      }else{
        int till=segY.query(Y);
        res=x-zip[till];

        segX.set(till,X+1,0,0,segX.n,Y);
      }
      eaten.insert(mp(x,y));
    }
    printf("%d\n",res);
  }
  return 0;
}