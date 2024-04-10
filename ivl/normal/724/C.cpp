#include <bits/stdc++.h>

#define FOR(i,a,b) for (int i = (int)(a); i < (int)(b); ++i)
#define REP(i,n) FOR(i,0,n)
#define pb push_back
#define x first
#define y second

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef pair < ll, ll > pll;

const int oo = 1e9;
const ll ool = (ll)oo * oo;

ll gcd(ll x, ll y){
  while (y) x %= y, swap(x, y);
  return x;
}

int n, m, k;

pll extgcd(pll x, pll y, ll Mod){
  while (y.x != 0){
    ll tmp = x.x/y.x;
    x.x -= y.x*tmp;
    x.y -= y.y*tmp;
    x.y %= Mod;
    if (x.y < 0) x.y += Mod;
    swap(x, y);
  }
  if (y.y != 0) return {ool, ool};
  else return x;
}

ll f(ll x, ll y){

  ll nn = 2*n, mm = 2*m;
  ll g = gcd(nn, mm);
  ll a = nn/g;
  ll b = mm/g;

  pll sol = extgcd({b, x*b}, {a, y*a}, a*b*g);
  if (sol.x == ool) return ool;
  assert(sol.x == 1);
  return sol.y;
  
}

ll solve(int x, int y){

  ll r = min(min(f(x, y), f(2*n-x, y)), min(f(x, 2*m-y), f(2*n-x, 2*m-y)));
  if (r == ool) return -1;
  return r;
  
}

int main(){
  ios_base::sync_with_stdio(false);
  
  cin >> n >> m >> k;
  REP(i,k){int x, y; cin >> x >> y; cout << solve(x, y) << endl;}
  
  return 0;
}