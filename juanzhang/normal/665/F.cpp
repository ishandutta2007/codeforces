#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=650000;

int ptt,pri[maxn];
void sieve(){
  int N=sqrt(1e11)+1;
  rep(i,2,N){
    if(!pri[i])pri[++ptt]=i;
    rep(j,1,ptt){
      if(i*pri[j]>N)break;
      pri[i*pri[j]]=1;
      if(i%pri[j]==0)break;
    }
  }
}

ll n,ans,dp[maxn],vmp[maxn];
int sqrt_n,vtt,itt,id1[maxn],id2[maxn];
ll&getdp(ll x){
  return dp[x<=sqrt_n?id1[x]:id2[n/x]];
}

signed main(){
  sieve();
  cin>>n,sqrt_n=sqrt(n);
  rep(i,1,ptt)ans+=1ll*pri[i]*pri[i]*pri[i]<=n;
  for(ll l=1;l<=n;l=n/(n/l)+1){
    ll x=n/l;
    x<=sqrt_n?id1[x]=++itt:id2[n/x]=++itt,vmp[++vtt]=n/l;
  }
  rep(i,1,vtt)getdp(vmp[i])=vmp[i]-1;
  rep(i,1,ptt){
    rep(j,1,vtt){
      if(vmp[j]<1ll*pri[i]*pri[i])break;
      getdp(vmp[j])+=i-1-getdp(vmp[j]/pri[i]);
    }
  }
  rep(i,1,ptt)if(pri[i]<sqrt_n)ans+=getdp(n/pri[i])-i;
  cout<<ans<<endl;
  return 0;
}