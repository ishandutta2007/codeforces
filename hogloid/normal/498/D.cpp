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
int freq[100005];

struct segtree{
  int val[270005][61];
  int n;

  void merge(int i){
    REP(j,60){
      int nxt=(j+val[i*2+1][j])%60;
      val[i][j]=val[i*2+2][nxt]+val[i*2+1][j];
    }
  }

  void init(int n_){
    n=1;
    while(n<n_) n<<=1;
    REP(i,n_){
      REP(j,60){
        if(j%freq[i]==0) val[i+n-1][j]=2;
        else val[i+n-1][j]=1;
      }
    }
    for(int i=n-2;i>=0;--i){
      merge(i);
    }
  }

  void set(int k,int a){
    freq[k]=a;
    k+=n-1;
    REP(j,60){
      if(j%a==0) val[k][j]=2;
      else val[k][j]=1;
    }

    while(k){
      k=(k-1)/2;
      merge(k);
    }
  }
  int query(int a,int b,int i,int l,int r,int k){
    if(a<=l && r<=b){
      return k+val[i][k%60];
    }
    if(b<=l || r<=a) return k;
    int md=(l+r)>>1;
    k=query(a,b,i*2+1,l,md,k);
    k=query(a,b,i*2+2,md,r,k);
    return k;
  }
};

segtree seg;
 
int main(){
  cin>>n;
  REP(i,n) scanf("%d",&freq[i]);

  int q;cin>>q;
  seg.init(n);
  REP(hoge,q){
    int x,y;
    char tmp[5];scanf("%s%d%d",tmp,&x,&y);
    if(tmp[0]=='A'){
      --x;--y;
      int res=seg.query(x,y,0,0,seg.n,0);
      printf("%d\n",res);
    }else{
      --x;
      seg.set(x,y);
    }
  }
  return 0;
}