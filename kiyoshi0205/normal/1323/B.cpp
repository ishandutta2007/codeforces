#include<bits/stdc++.h>
using namespace std;
int N,M,K,cnta[40001],cntb[40001],cnt;
long long ans;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>N>>M>>K;
  for(int t=0;t<N;++t){
    int x;
    cin>>x;
    if(x)++cnt;
    else{
      for(int i=1;i<=cnt;++i)cnta[i]+=cnt-i+1;
      cnt=0;
    }
  }
  for(int i=1;i<=cnt;++i)cnta[i]+=cnt-i+1;
  cnt=0;
  for(int t=0;t<M;++t){
    int x;
    cin>>x;
    if(x)++cnt;
    else{
      for(int i=1;i<=cnt;++i)cntb[i]+=cnt-i+1;
      cnt=0;
    }
  }
  for(int i=1;i<=cnt;++i)cntb[i]+=cnt-i+1;
  int d;
  for(d=1;d*d<K;++d){
    if(K%d)continue;
    if(d<=N&&K/d<=M)ans+=1LL*cnta[d]*cntb[K/d];
    if(d<=M&&K/d<=N)ans+=1LL*cntb[d]*cnta[K/d];
  }
  if(d*d==K&&d<=min(N,M))ans+=1LL*cnta[d]*cntb[d];
  cout<<ans<<'\n';
}