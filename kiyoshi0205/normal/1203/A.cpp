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
  ll i,j,N,Q,bf,f;
  cin>>Q;
while(Q--){
  cin>>N;
  vector<ll> v(N);
  rep(i,N){
    cin>>v[i];
    v[i]--;
  }
  if(N==1){cout<<"YES"<<endl;continue;}

  bf=v[0];
  f=1;
  if(bf==0){
    if(v[1]==1){
      rep1(i,N){
        if(v[i]!=(bf+1)%N){
          cout<<"NO"<<endl;
          f=0;
          break;
        }
        bf=v[i];
      }
      if(f)cout<<"YES"<<endl;
    }else{
      rep1(i,N){
        if(v[i]!=(bf+N-1)%N){
          cout<<"NO"<<endl;
          f=0;
          break;
        }
        bf=v[i];
      }
      if(f)cout<<"YES"<<endl;
    }
    continue;
  }
  if(bf==N-1){
    if(v[1]==0){
      rep1(i,N){
        if(v[i]!=(bf+1)%N){
          cout<<"NO"<<endl;
          f=0;
          break;
        }
        bf=v[i];
      }
      if(f)cout<<"YES"<<endl;
    }else{
      rep1(i,N){
        if(v[i]!=(bf+N-1)%N){
          cout<<"NO"<<endl;
          f=0;
          break;
        }
        bf=v[i];
      }
      if(f)cout<<"YES"<<endl;
    }
    continue;
  }
  if(v[1]>v[0]){
    rep1(i,N){
      if(v[i]!=(bf+1)%N){
        cout<<"NO"<<endl;
        f=0;
        break;
      }
      bf=v[i];
    }
    if(f)cout<<"YES"<<endl;
  }else{
    rep1(i,N){
      if(v[i]!=(bf+N-1)%N){
        cout<<"NO"<<endl;
        f=0;
        break;
      }
      bf=v[i];
    }
    if(f)cout<<"YES"<<endl;
  }
}
  return 0;
}