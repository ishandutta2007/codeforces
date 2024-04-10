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
typedef vector<ll> vll;

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
  cin >> N;
  vll v(N), a(N,0);
  for(int i = 0; i < N; i++){
    cin >> v[i];
  }
ll q = 1;
  for(ll i = 0; i < 20; i++){
    int c = 0;
    for(int j = 0; j < N; j++)if(v[j]&q)c++;
    for(int j = 0; j < c; j++)a[j]+=q;
    q*=2;
  }

  ll r = 0;
  for(auto x: a)r+=x*x;
  cout << r;
  return 0;
}