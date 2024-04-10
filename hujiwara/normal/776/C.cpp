#include <bits/stdc++.h>
using namespace std;

const long long INF=1000000000000000ll;

int main()
{
  int n,k;
  static long long a[100000];
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%lld",a+i);
  }
  map<long long,int> M;
  long long S=0;
  long long ans=0ll;
  for(int i=0;i<=n;i++){
    long long K=1ll;
    while(1){
      long long W=S-K;
      //printf("%lld %lld\n",S,W);
      if(W<-INF){
	break;
      }
      if(M.find(W)!=M.end()){
	ans+=M[W];
      }
      if(k==1||(k==-1&&K==-1)){
	break;
      }
      K*=k;
    }
    if(M.find(S)==M.end()){
      M[S]=1;
    }
    else{
      M[S]++;
    }
    if(i<n){
      S+=a[i];
    }
  }
  printf("%lld\n",ans);
  return 0;
}