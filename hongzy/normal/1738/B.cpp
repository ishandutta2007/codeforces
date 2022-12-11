#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int n, k;
ll s[N];
bool check(vector<ll> s) {
  for(int i = 1; i < int(s.size()); i ++)
    if(s[i] < s[i-1]) return 0;
  return 1;
}
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d%d", &n, &k);
    rep(i, 1, k) scanf("%lld", s + i);
    vector<ll> v;
    rep(i, 2, k)
      v.pb(s[i] - s[i-1]);
    if(!check(v))
      puts("No");
    else {
      if(k == 1)
        puts("Yes");
      else {
        ll lim = *v.begin();
        if((n - k + 1) * lim < s[1])
          puts("No");
        else
          puts("Yes");
      }
    }
  }
  return 0;
}