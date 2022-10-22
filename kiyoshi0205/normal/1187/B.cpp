#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define Rep(i,N) for(i=0;i<N;i++)
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
  Rep(i,r){
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
  int i,j,N,K,ans,p,q;
  string ss;
  cin >>N;
  cin >>ss;
  vector<vector<int>> order(26,vector<int>(N,0));
  vector<int> cnt(26,0);
  Rep(i,N){
    p=ss[i]-'a';
    order[p][cnt[p]++]=i+1;
  }
  cin>>N;
  Rep(i,N){
    cin >>ss;
    K=ss.size();
    vector<int> cou(30,0);
    ans=0;
    Rep(j,K){
      q=ss[j]-'a';
      p=order[q][cou[q]++];
      if(ans<p)ans=p;
    }
    cout <<ans <<endl;
  }
/*     K=ss.size();
    queri.resize(K);
    Rep(j,K){
      queri[j]=ss[j]-'a';
    }
    sort(queri.begin(),queri.end());
    bf=queri[0];
    ans=order[bf][cou++];
    Rep(j,K){
      if(j)
    }*/
  return 0;
}