#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(i=0;i<N;i++)
#define rep1(i,N) for(i=1;i<N;i++)
#define mod 1000000007

long mmid(long a,long b,long c){return a<b?(b<c?b:max(a,c)):(b>c?b:min(a,c));}

ll modinv(ll a) {
  ll b=mod,u=1,v=0,t;
  while(b){
    t=a/b;
    a-=t*b; swap(a,b);
    u-=t*v; swap(u,v);
  }
  return (u+mod)%mod;
}

ll moddevide(ll a,ll b){return (a*modinv(b))%mod;}
 
ll modncr(ll n,ll r){
  ll i,plus=1;
  rep(i,r){
    plus=(plus*(n-i))%mod;
    plus=moddevide(plus,i+1);
  }
  return plus;
}

ll euclidean_gcd(ll a, ll b) {
  if(a<b) return euclidean_gcd(b, a);
  ll r;
  while ((r=a%b)){a=b;b=r;}
  return b;
}

int main(){
  int i,N,K,a,b,ch,now;
  long t;
  cin>>N;
  vector<vector<int>> v(N);
  rep(i,N-1){
    cin>>a>>b;
    a--;b--;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  rep(i,N){
    K=v[i].size();
    if(K==2){
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}