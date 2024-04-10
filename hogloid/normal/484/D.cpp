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
int ar[1000005];

lint dp[1000005];

int nxt[1000005];
lint solve(int* ar,int n){//no two adjacent elements are same
  if(n==1) return 0;

  REP(i,n+1) dp[i]=0;

  REP(i,n-1){
    int j=i+1;
    if(ar[i+1]>ar[i]){
      while(j<n && ar[j]>ar[j-1]) ++j;

      REPN(k,j-1,i) nxt[k]=j;
    }else{
      while(j<n && ar[j]<ar[j-1]) ++j;

      REPN(k,j-1,i) nxt[k]=j;
    }
    i=j-2;
  }

  REP(i,n){
    chmax(dp[i+1],dp[i]);
    if(i+1<n){
      if(ar[i+1]>ar[i]){//increase
        int j=nxt[i];
        //[i...j)
        chmax(dp[j],dp[i]+ar[j-1]-ar[i]);
        chmax(dp[j-1],dp[i]+ar[j-2]-ar[i]);
      }else{
        int j=nxt[i];
        chmax(dp[j],dp[i]+ar[i]-ar[j-1]);
        chmax(dp[j-1],dp[i]+ar[i]-ar[j-2]);
      }
    }
  }
  return dp[n];
}
int main(){
  cin>>n;
  REP(i,n) scanf("%d",&ar[i]);

  lint res=0;

  int begin=0;
  REP(i,n-1) if(ar[i]==ar[i+1]){
    res+=solve(ar+begin,i+1-begin);
    begin=i+1;
  }
  res+=solve(ar+begin,n-begin);
  cout<<res<<endl;

  return 0;
}