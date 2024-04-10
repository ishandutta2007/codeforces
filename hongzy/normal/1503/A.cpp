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

const int N = 4e5 + 10;
const int mod = 1e9 + 7;
int n;
char s[N], t[N], t2[N];
int main() {
  int A; scanf("%d", &A);
  while(A --) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    // n = strlen(s + 1);
    int c = 0;
    rep(i, 1, n) c += s[i] == '1';
    if(c % 2 || s[1] == '0' || s[n] == '0') puts("NO");
    else {
      puts("YES");
      int cur = 0;
      t[n + 1] = t2[n + 1] = 0;
      rep(i, 1, n) if(s[i] == '1') {
        ++ cur;
        if(cur <= c / 2) t[i] = t2[i] = '(';
        else t[i] = t2[i] = ')';
      }
      cur = 0;
      rep(i, 1, n) if(s[i] == '0') {
        cur ^= 1;
        t[i] = cur ? '(' : ')';
        t2[i] = cur ? ')' : '(';
      }
      puts(t + 1);
      puts(t2 + 1);
    }
  }
  return 0;
}