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

int main(){
  startupcpp();
//  ll test;cin>>test;while(test--){
  ll i,j,k,N,cnt=0,ans=0;
  cin>>N;
  if(N==1){
    cout<<0<<endl;
    return 0;
  }
  vec v(2,0),a(N);
  mat edge(2);
  rep(i,N){
    cin>>a[i];
    if(a[i])v[a[i]&1]--;
    v[(i+1)&1]++;
    if(i&&a[i]&&a[i-1]&&(a[i]+a[i-1])%2)ans++;
  }
  if(v[0]+v[1]==N){
    print(1);
    return 0;
  }
  i=0;
  if(!a[0]){
    while(!a[i])i++;
    edge[a[i]&1].pb(i);
  }
  j=N-1;
  if(!a[j]){
    while(!a[j])j--;
    edge[a[j]&1].pb(N-1-j);
  }
  // rep(i,2)output(edge[i]);
  if(edge[0].size()>1)vsort(edge[0]);
  if(edge[1].size()>1)vsort(edge[1]);
  if(i==j){
    print(1);
    return 0;
  }
  //start=i;
  priority_queue<datas,pvec,greater<datas>> que;
  // print(cnt<<" "<<ans);
  //cnt can any minus;
  while(i<j){
    if(a[i+1]){
      i++;
      continue;
    }
    k=1;
    while(!a[i+k])k++;
    if((a[i+k]+a[i])%2==0){
      que.push(datas(k-1,a[i+k]&1));
      // if(v[a[i]&1]>=k-1){
      //   v[a[i]&1]-=k-1;
      // }else{
      //   v[(a[i]+1)&1]-=k-1-v[a[i]&1];
      //   v[a[i]&1]=0;
      //   ans+=2;
      // }
    }else{
      cnt+=k-1;
      ans+=1;
    }
    i+=k;
  }
  // print(cnt<<" "<<ans);
  // output(v);
  //rep(i,2)output(edge[i]);
  while(!que.empty()){
    auto x=que.top();que.pop();
    if(v[x.second]>=x.first){
        v[x.second]-=x.first;
    }else{
      if(edge[x.second].size()){
        for (auto p:edge[x.second]){
          if(v[x.second]>=p){
            v[x.second]-=p;
          }else{
            v[x.second^1]-=p-v[x.second];
            v[x.second]=0;
            ans++;
          }
        }
        edge[x.second].clear();
      }
      v[x.second^1]-=x.first-v[x.second];
      v[x.second]=0;
      ans+=2;
    }
  }
  //output(v);
  rep(i,2){
    //output(edge[i]);
    for (auto p:edge[i]){
      if(v[i]>=p){
        v[i]-=p;
      }else{
        v[i^1]-=p-v[i];
        v[i]=0;
        ans++;
      }
    }
  }
  // if(v[0]+v[1]>cnt){
  //   if(!a[0]){
  //     if(v[a[start]&1]>=start){
  //       v[a[start]&1]-=start;
  //     }else{
  //       ans++;
  //       v[(a[start]+1)&1]-=start-v[a[start]&1];
  //       v[a[start]&1]=0;
  //     }
  //   }
  //   if(!a[N-1]){
  //     if(v[a[j]&1]>=N-1-j){
  //       print(ans);
  //       return 0;
  //     }else{
  //       print(ans+1);
  //       return 0;
  //     }
  //   }
  // }
  print(ans);
  return 0;
}