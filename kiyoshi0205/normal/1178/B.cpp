#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using vec=vector<ll>;
using mat=vector<vec>;
#define For(i,a,b) for(i=a;i<b;i++)
#define rep(i,N) For(i,0,N)
#define rep1(i,N) For(i,1,N)
#define all(v) (v).begin(),(v).end()
#define vsort(v) sort(all(v))
#define mod 1000000007
using data=pair<ll,ll>;

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

void printmap(vector<ll>& a,ll H,ll W){
  ll i,j;
  For(i,0,H+2){
    For(j,0,W+2){cout<<a[i*(W+2)+j];}
    cout<<endl;
  }
}
void inputmap(vector<ll>& a,ll H,ll W){
  ll i,j;
  string ss;
  For(i,1,H+1){
    cin>>ss;
    For(j,1,W+1){
      if(ss[j-1]=='#'){
        a[i*(W+2)+j]=1;
      }else{
        a[i*(W+2)+j]=0;
      }
    }
  }
}


int main(){
  ll i,N,K,x,cnt=0,ans=0;
  vector<ll> v;
  string ss;
  cin>>ss;
  N=ss.size();
  if(ss[0]=='o')v.push_back(0);
  rep1(i,N){
    if(ss[i]=='o'){
      if(cnt){v.push_back(cnt);cnt=0;}
      v.push_back(0);
    }else if(ss[i]==ss[i-1]){
      cnt++;
    }else{
      if(cnt){v.push_back(cnt);cnt=0;}
    }
  }
  if(cnt){v.push_back(cnt);cnt=0;}

  N=v.size();
  vec rst(N,0),lst(N,0);
  rep(i,N){
    if(v[i]){
      if(cnt==0){rst[cnt++]=v[i];continue;}
      rst[cnt]=rst[cnt-1]+v[i];
      cnt++;
    }
  }
  K=cnt;
  cnt-=2;
  for(i=N-1;i>=0;i--){
    if(v[i]){
      if(cnt<0)break;
      lst[cnt]=lst[cnt+1]+v[i];
      cnt--;
    }
  }

  i=0;
  cnt=-1;
  rep(i,N){
    if(v[i]==0){
      if(cnt<0)continue;
      ans+=rst[cnt]*lst[cnt];
    }else{
      cnt++;
    }
  }
  cout<<ans<<endl;
  return 0;
}