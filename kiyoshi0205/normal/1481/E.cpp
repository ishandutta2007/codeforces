#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;}
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;}


void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

int main(){
  startupcpp();
  int N;
  cin>>N;
  //,index,index,
  //dp[i]:imin
  vector<int> v(N),l(N,N),r(N,-1),cnt(N,0),dp(N+2,N);
  for(int i=0;i<N;++i){
    cin>>v[i];
    --v[i];
    chmin(l[v[i]],i);
    chmax(r[v[i]],i);
    cnt[v[i]]++;
  }
  dp[0]=0;
  for(int i=0;i<N;++i){
    //v[i]
    chmin(dp[i+1],dp[i]+1);
    //
    //v[i]()
    if(l[v[i]]==i)chmin(dp[r[v[i]]+1],dp[i]+(r[v[i]]-l[v[i]]+1)-cnt[v[i]]);
    //
    chmin(dp[N],dp[i]+(N-i)-cnt[v[i]]);

    cnt[v[i]]--;
  }
  cout<<dp[N]<<"\n";
}