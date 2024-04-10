#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
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
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 5e5 + 10;
const int mod = 1e9 + 7;
int n, p[N], q[N];
char a[N], b[N], c[N];
bool out(char *s, char *t, char ch) {
  int c1 = 0, c2 = 0;
  rep(i, 1, 2 * n) {
    c1 += s[i] == ch;
    c2 += t[i] == ch;
    if(s[i] == ch) p[c1] = i;
    if(t[i] == ch) q[c2] = i;
  }
  if(c1 < n || c2 < n) return 0;
  q[0] = p[0] = 0; q[n + 1] = p[n + 1] = 2 * n + 1;
  string ans;
  rep(i, 1, n + 1) {
    rep(j, p[i - 1] + 1, p[i] - 1) ans.pb(s[j]);
    rep(j, q[i - 1] + 1, q[i] - 1) ans.pb(t[j]);
    if(i != n + 1) ans.pb(ch);
  }
  // cerr << "! ";
  puts(ans.c_str());
  return 1;
}
int main() {
  int t; scanf("%d", &t);
  while(t --) {
    scanf("%d", &n);
    scanf("%s%s%s", a + 1, b + 1, c + 1);
    if(out(a, b, '0'));
    else if(out(a, b, '1'));
    else if(out(a, c, '0'));
    else if(out(a, c, '1'));
    else if(out(b, c, '0'));
    else out(b, c, '1');
  }
  return 0;
}