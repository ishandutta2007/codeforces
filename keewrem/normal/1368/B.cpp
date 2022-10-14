#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) x.begin(),x.end()
#define fi first
#define se second

typedef long long ll;
typedef string str;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;

const ll MOD = 1000000007;
const ll mxn = 200000;

ll fxp(ll b, ll e){
  ll r = 1;
  for(ll i = 0; i < 60; i++){
    if((1LL<<i)&e){r*=b; r%=MOD;}
    b=(b*b)%MOD;
  }
  return r;
}

ll inv(ll a){
  return fxp(a,MOD-2);
}

ll fact[mxn+1];
ll finv[mxn+1];

void ffff(){
  fact[0]=1;
  for(int i = 1; i <= mxn; i++)fact[i]=(fact[i-1]*i)%MOD;
  finv[mxn]=inv(fact[mxn]);
  for(int i = mxn-1; i>=0; i--)finv[i]=(finv[i+1]*(i+1))%MOD;
}

ll N,T,M;

int main(){
  ll k;
  cin >> k;
  ll p = 1;
  vi v(10,1);
  while(p < k)for(int i = 0; i < 10; i++){
    v[i]+=1; p = (p/(v[i]-1))*v[i];
    if(p >= k)break;
  }
  string s = "codeforces";
  for(int i = 0; i < 10; i++)while(v[i]--)cout << s[i];
  return 0;
}