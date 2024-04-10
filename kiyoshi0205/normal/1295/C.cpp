#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
using mat=vector<vec>;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define mod 1000000007
ll inf=1LL<<60;
ll N,K;
ll search(ll key,mat& alp,ll now){
  ll M=alp[key].size();
  if(M==1){
    cout<<-1<<endl;
    return -inf;
  }
  ll ok=M-1,ng=0;
  while(ok-ng>1){
    ll mid=(ok+ng)/2;
    if(alp[key][mid]>=now){
      ok=mid;
    }else{
      ng=mid;
    }
  }
  return alp[key][ok];
}
int main(){
  ll test;cin>>test;while(test--){
  ll i,now=-1,ans=0,f=1;
  string s,t;cin>>s>>t;
  N=s.size();K=t.size();
  mat alp(26);
  rep(i,26)alp[i].push_back(-5);
  rep(i,N){
    alp[s[i]-'a'].push_back(i);
  }
  rep(i,26){
    if(alp[i].size()>1)alp[i].push_back(alp[i][1]+N);
  }
  rep(i,K){
    now=search(t[i]-'a',alp,now+1);
    if(now==-inf){
      f=0;
      break;
    }
    if(now>=N){
      ans++;
      now-=N;
    }
  //cout<<ans*N+now+1<<endl;
  }
  if(f)cout<<(ans*N+now+s.size())/s.size()<<endl;
}  return 0;
}