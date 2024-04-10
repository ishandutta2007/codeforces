#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/tag_and_trait.hpp>
// using namespace __gnu_pbds;
using namespace std;
using ll=long long;
#define double long double
using datas=pair<ll,ll>;
using ddatas=pair<double,double>;
using tdata=pair<ll,datas>;
using vec=vector<ll>;
using mat=vector<vec>;
using pvec=vector<datas>;
using pmat=vector<pvec>;
// using llset=tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>;
#define For(i,a,b) for(i=a;i<(ll)b;i++)
#define bFor(i,a,b) for(i=a;i>=(ll)b;i--)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define brep(i,N) bFor(i,N-1,0)
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define vsort(v) sort(all(v))
#define vrsort(v) sort(allr(v))
#define endl "\n"
#define pb push_back
#define eb emplace_back
#define print(v) cout<<v<<endl
#define printyes cout<<"Yes"<<endl
#define printno cout<<"No"<<endl
#define printYES cout<<"YES"<<endl
#define printNO cout<<"NO"<<endl
#define output(v) do{bool f=0;for(auto outi:v){cout<<(f?" ":"")<<outi;f=1;}cout<<endl;}while(0)
const ll mod=1000000007;
const ll inf=1LL<<60;
const double PI = acos(-1);
const double eps = 1e-9;
template<class T> inline bool chmax(T& a,T b){bool x=a<b;if(x)a=b;return x;} 
template<class T> inline bool chmin(T& a,T b){bool x=a>b;if(x)a=b;return x;} 

void startupcpp(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout<<fixed<<setprecision(15);
}

double distance(ddatas x,ddatas y){
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
int main(){
  startupcpp();
  // ll test;cin>>test;while(test--){
  ll i,j,N,a,b;
  cin>>N;
  mat g(N,vec(N)),ch(N,vec(N,0)),ans(N,vec(N,-1));
  char printout[6]="XLRUD";
  rep(i,N){
    rep(j,N){
      cin>>a>>b;
      if(a==-1)g[i][j]=-1;
      else g[i][j]=(a-1)*N+b-1;
    }
  }
  //-1check
  rep(i,N)rep(j,N)if(g[i][j]==-1){
    if(i&&g[i-1][j]==-1){
      ch[i-1][j]=ch[i][j]=1;
      ans[i][j]=3;
      ans[i-1][j]=4;
    }
    if(j&&g[i][j-1]==-1){
      ch[i][j-1]=ch[i][j]=1;
      ans[i][j]=1;
      ans[i][j-1]=2;
    }
    if(i<N-1&&g[i+1][j]==-1){
      ch[i+1][j]=ch[i][j]=1;
      ans[i][j]=4;
      ans[i+1][j]=3;
    }
    if(j<N-1&&g[i][j+1]==-1){
      ch[i][j+1]=ch[i][j]=1;
      ans[i][j]=2;
      ans[i][j+1]=1;
    }
    if(!ch[i][j]){
      print("INVALID");
      return 0;
    }
  }
  //root check
  queue<datas> que;
  rep(i,N)rep(j,N)if(g[i][j]==i*N+j){
    ch[i][j]=1;
    ans[i][j]=0;
    que.push(datas(i,j));
    while(!que.empty()){
      auto x=que.front();que.pop();
      a=x.first;b=x.second;
      if(a&&g[a-1][b]==g[a][b]&&!ch[a-1][b]){
        ch[a-1][b]=1;
        ans[a-1][b]=4;
        que.push(datas(a-1,b));
      }
      if(b&&g[a][b-1]==g[a][b]&&!ch[a][b-1]){
        ch[a][b-1]=1;
        ans[a][b-1]=2;
        que.push(datas(a,b-1));
      }
      if(a<N-1&&g[a+1][b]==g[a][b]&&!ch[a+1][b]){
        ch[a+1][b]=1;
        ans[a+1][b]=3;
        que.push(datas(a+1,b));
      }
      if(b<N-1&&g[a][b+1]==g[a][b]&&!ch[a][b+1]){
        ch[a][b+1]=1;
        ans[a][b+1]=1;
        que.push(datas(a,b+1));
      }
    }
  }
  rep(i,N)rep(j,N){
    if(!ch[i][j]){
      print("INVALID");
      return 0;
    }
  }
  print("VALID");
  rep(i,N){
    rep(j,N){
      cout<<printout[ans[i][j]];
    }
    cout<<endl;
  }
}