#include <bits/stdc++.h>
#define debug(...) fprintf(stderr, __VA_ARGS__);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() {
  ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }
int n, a[N];
int query(int x) {
  if(x <= 0 || x > n) return mod;
  cout << "? " << x << endl;
  int y; cin >> y; return y;
}
void solve(int l, int r) {
  if(l == r) {
    cout << "! " << l << endl;
    return ;
  }
  int mid = (l + r) >> 1;
  int x = query(mid), y = query(mid - 1), z = query(mid + 1);
  if(x < y && x < z) {
    cout << "! " << mid << endl;
    return ;
  }
  if(a[1] < x) return solve(l, mid - 1);
  if(a[n] < x) return solve(mid + 1, r);
  if(y < z) return solve(l, mid - 1);
  return solve(mid + 1, r);
}
int main() {
  ucin();
  cin >> n;
  if(n == 1) {
    cout << "! " << 1 << endl;
    return 0;
  }
  if(n == 2) {
    if(query(1) == 1) {
      cout << "! " << 1 << endl;
    } else {
      cout << "! " << 2 << endl;
    }
    return 0;
  }
  if(query(2) > (a[1] = query(1))) {
    cout << "! " << 1 << endl;
    return 0;
  }
  if(query(n - 1) > (a[n] = query(n))) {
    cout << "! " << n << endl;
    return 0;
  }
  solve(1, n);
  return 0;
}