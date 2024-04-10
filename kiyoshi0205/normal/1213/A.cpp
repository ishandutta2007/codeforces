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
using datas=pair<ll,ll>;
using tdata=pair<datas,ll>;

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
  ll i,N,ans[2]={0},x;
  cin>>N;
  rep(i,N){
    cin>>x;
    ans[x%2]++;
  }
  cout<<min(ans[0],ans[1])<<endl;
  return 0;
}