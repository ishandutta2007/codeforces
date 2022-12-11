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
unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int a, b, k;
int main() {
  cin >> a >> b >> k;
  if(a == 0) {
    if(k == 0) {
      cout << "Yes\n";
      rep(i, 1, b) cout << '1';
      cout << endl;
      rep(i, 1, b) cout << '1';
      cout << endl;
    } else {
      cout << "No\n";
    }
    return 0;
  }
  if(k >= a + b) {
    cout << "No\n";
    return 0;
  }
  if(k == 0) {
    cout << "Yes\n";
    rep(i, 1, b + a) cout << (i <= b ? 1 : 0);
    cout << endl;
    rep(i, 1, b + a) cout << (i <= b ? 1 : 0);
    cout << endl;
    return 0;
  }
  int bit = min(b + k, b + a);
  if(bit - k == 1) {
    cout << "No\n";
    // cout << endl;
    return 0;
  }
  cout << "Yes\n";
  rep(i, 1, b + a) cout << (i <= b ? 1 : 0);
  cout << endl;
  rep(i, 1, b + a) {
    if(i == bit - k) cout << 0;
    else if(i == bit) cout << 1;
    else cout << (i <= b ? 1 : 0);
  }
  cout << endl;
  return 0;
}