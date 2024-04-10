#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
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
#define endl "\n"
#define pb push_back
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
const ll mod=1000000007;
const ll inf=1LL<<60;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

double distance(ddatas& x,ddatas& y){
  double a=x.first-y.first,b=x.second-y.second;
  return sqrt(a*a+b*b);
}

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

vec modncrlistp,modncrlistm;

ll modncr(ll n,ll r){
  ll i,size=modncrlistp.size();
  if(size<=n){
    modncrlistp.resize(n+1);
    modncrlistm.resize(n+1);
    if(!size){
      modncrlistp[0]=modncrlistm[0]=1;
      size++;
    }
    For(i,size,n+1){
      modncrlistp[i]=modncrlistp[i-1]*i%mod;
      modncrlistm[i]=modinv(modncrlistp[i]);
    }
  }
  return modncrlistp[n]*modncrlistm[r]%mod*modncrlistm[n-r]%mod;
}

ll modpow(ll a,ll n){
  ll res=1;
  while(n){
    if(n&1)res=res*a%mod;
    a=a*a%mod;
    n>>=1;
  }
  return res;
}

ll gcd(ll a,ll b){if(!b)return a;return (a%b==0)?b:gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

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
 
struct segtree{
  ll N;
  vec tree;
  segtree(ll K,vec& v){
    N=1;
    while(N<K)N*=2;
    ll i;
    tree.resize(2*N-1);
    For(i,N-1,N-1+K){
      tree[i]=v[i-N+1];
    }
    For(i,N+K-1,2*N-1){
      tree[i]=0;
    }
    brep(i,N-1){
      tree[i]=tree[i*2+1]|tree[i*2+2];
    }
  }
  void input(ll i,ll a){
    i+=N-1;
    tree[i]=a;
    while(i){
      i=(i-1)/2;
      tree[i]=tree[i*2+1]|tree[i*2+2];
    }
  }
  ll res(ll a,ll b,ll k,ll l,ll r){
    if(r<0)r=N;
    if(r<=a||b<=l)return 0;
    if(a<=l&&r<=b)return tree[k];
    ll vl=res(a,b,2*k+1,l,(l+r)/2);
    ll vr=res(a,b,2*k+2,(l+r)/2,r);
    return vl|vr;
  }
  ll q(ll a,ll b){
    return res(a,b,0,0,-1);
  }
  void prt(){
    output(tree);
  }
};
int main(){
  ll i,N,Q,x,qt,l,r,ans;
  string s,t;cin>>s;
  N=s.size();
  cin>>Q;
  vec v(N),alp(30,1);
  rep1(i,30)alp[i]=alp[i-1]*2;
  rep(i,N){
    x=s[i]-'a';
    v[i]=alp[x];
  }
  segtree tree(N,v);
  while(Q--){
    cin>>qt;
    if(qt-1){
      cin>>l>>r;
      l--;
      x=tree.q(l,r);
      ans=0;
      while(x){
        ans+=x%2;x/=2;
      }
      cout<<ans<<endl;
    }else{
      cin>>i>>t;
      i--;
      x=t[0]-'a';
      tree.input(i,alp[x]);
    }
  }
  return 0;
}