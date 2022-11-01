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
int ar[200005];
int res[200005],sum[200005];
const int B=500;

inline int par(int a,int k){
  return (a+k-2)/k;
}
pi range[505];//[a...b)
int main(){
  cin>>n;
  REP(i,n) scanf("%d",&ar[i+1]);

  REP(i,B) range[i]=mp(1,1);
  range[1]=mp(1,n);
  for(int i=2;i<=n;++i){
    for(int j=1;j<min(B,n+1);++j){
      if(ar[j]>ar[i]){
        sum[range[j].fr]++;
        sum[range[j].sc]--;
      }
      while(range[j].fr<=n+1 && j<par(i+1,range[j].fr)) ++range[j].fr;
      while(range[j].sc<=n+1 && j<=par(i+1,range[j].sc)) ++range[j].sc;
    }

    for(int k=1;k<B;++k){
      int p=par(i,k);
      if(p<B) break;
      if(ar[p]>ar[i]) ++res[k];
    }
  }
  REP(i,n+1) sum[i+1]+=sum[i];

  for(int k=1;k<n;++k) printf("%d\n",res[k]+sum[k]);


  return 0;
}