#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(ll i = a; i < b; ++i)
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

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  ll n; cin >> n;
  if(n == 1) {
    cout << 1 << endl;
    return 0;
  }

  ll mini = 1;

  FOR(i, 2, n + 1) {
    if((ll) i * i > n) {
      mini = n;
      break;
    }
    if(n % ((ll) i) == 0) {
      mini = i;
      break;
    }
  }
  while(n % mini == 0) n /= mini;
  if(n == 1) {
    cout << mini << endl;
  }
  else {
    cout << 1 << endl;
  }
  return 0;
}