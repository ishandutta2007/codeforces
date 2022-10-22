#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
#define For(i,a,b) for(i=a;i<b;i++)
#define bFor(i,a,b) for(i=a;i>=b;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N-1,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define mod 1000000007
#define endl "\n"
#define output(v) do{bool f=0;for(auto i:v){cout<<(f?" ":"")<<i;f=1;}cout<<endl;}while(0)

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

ll modncrlistp[200000],modncrlistm[200000];

ll modncrs(ll n,ll r){
  ll i,j;
  if(modncrlistp[n]==0){
    for(i=n;i>=0;i--){
      if(modncrlistp[i])break;
    }
    if(i<0){
      modncrlistp[0]=1;
      rep1(i,n+1){
        modncrlistp[i]=(modncrlistp[i-1]*i)%mod;
      }
    }else{
      For(j,i+1,n+1){
        modncrlistp[j]=(modncrlistp[j-1]*j)%mod;
      }
    }
  }
  if(modncrlistm[n]==0){
    for(i=n;i>=0;i--){
      if(modncrlistm[i])break;
    }
    if(i<0){
      modncrlistm[0]=1;
      rep1(i,n+1){
        modncrlistm[i]=(modncrlistm[i-1]*modinv(i))%mod;
      }
    }else{
      For(j,i+1,n+1)modncrlistm[j]=(modncrlistm[j-1]*modinv(j))%mod;
    }
  }
  return (((modncrlistp[n]*modncrlistm[r])%mod)*modncrlistm[n-r])%mod;
}

ll gcd(ll a,ll b){if(!b)return a;return (a%b==0)?b:gcd(b,a%b);}

ll countdigits(ll n){
  ll ans=0;
  while(n){n/=10;ans++;}
  return ans;
}

ll sumdigits(ll n){
  ll ans=0;
  while(n){ans+=n%10;n/=10;}
  return ans;
}

vec eratosthenes(ll N){
  ll i;
  vec ch(N+1,1),p;
  ch[0]=ch[1]=0;
  rep(i,N+1){
    if(ch[i]){
      p.push_back(i);
      for(ll j=2;i*j<=N;j++){
        ch[i*j]=0;
      }
    }
  }
  return ch;
}
int main(){
  ll i=1,N,K;
  string ss;cin>>N;
  cin>>K;
  cin>>ss;
  if(ss.size()==1&&K>0){
    cout<<0<<endl;
    return 0;
  }
  if(K==0){
    cout<<ss<<endl;
    return 0;
  }

  if(ss[0]!='1'){
    ss[0]='1';
    K--;
  }
  if(K==0){
    cout<<ss<<endl;
    return 0;
  }

  while(K>0&&i<(ll)ss.size()){
    if(ss[i]!='0'){
      ss[i]='0';
      K--;
    }
    i++;
  }
  cout<<ss<<endl;
  return 0;
}