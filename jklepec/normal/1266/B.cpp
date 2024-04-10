#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

bool check(ll x) {
  if(x % 14 == 0 && x >= 14) {
    return true;
  }
  return false;
}

void solve() {
  ll x; cin >> x;
  for(int i = 1; i < 7; i ++)  {
    if(check(x - i)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int t; cin >> t;
  while(t --) solve();
}