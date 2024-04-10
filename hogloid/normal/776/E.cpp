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
lint n,K;
lint f(lint a){
  lint res=0;
  for(lint i=1;i<=a;++i) if(__gcd(a,i)==1){
    ++res;
  }
  return res;
}
lint g(lint a){
  lint res=0;
  for(lint i=1;i*i<=a;++i) if(a%i==0){
    res+=f(i);
    if(i*i!=a) res+=f(a/i);
  }
  return res;
}
lint eulerPhi(lint n) {
  if (n == 0) return 0;
  lint ans = n;
  for (lint x = 2; x*x <= n; ++x) {
    if (n % x == 0) {
      ans -= ans / x;
      while (n % x == 0) n /= x;
    }
  }
  if (n > 1) ans -= ans / n;
  return ans;
}
int ar1[100005],br1[100005];
int main(){
  cin>>n>>K;

  lint ans=n;
  lint cnt=(K+1)/2;
  while(cnt--){
    dump(ans);
    if(ans==1) break;
    ans=eulerPhi(ans);
  }
  const lint mod=1000000007;
  ans%=mod;
  cout<<ans<<endl;
  return 0;
}