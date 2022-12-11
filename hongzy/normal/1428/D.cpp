#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;

#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;

typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

unsigned seed = chrono::system_clock::now().time_since_epoch().count();
mt19937 Rand(seed);
// mt19937_64 
uniform_int_distribution<ll> range(0, 1ll << 32);
inline void ucin() {
   ios::sync_with_stdio(0); cin.tie(0);
}
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }

const int N = 6e5 + 10;
const int INF = 2e9 + 10;

int qpow(int a, int b, int mod) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
      if(b & 1) ans = (ll) ans * a % mod;
   return ans;
}
int n, a[N], pos[N];
vector<pii> ans;
stack<int> a1, a2;
void fail() {
   puts("-1"); exit(0);
}
int main() {
   scanf("%d", &n);
   rep(i, 1, n) scanf("%d", a + i);
   int p = n;
   per(i, n, 1) if(a[i]) {
      if(a[i] == 1) {
         ans.pb(pii(p, i));
         a1.push(p); pos[p] = i;
         p --;
      } else if(a[i] == 2) {
         if(a1.size()) {
            ans.pb(pii(a1.top(), i)); a1.pop();
            a2.push(i);
         } else fail();
      } else if(a[i] == 3) {
         if(a2.size()) {
            int c = a2.top(); a2.pop();
            ans.pb(pii(p, c)); ans.pb(pii(p, i));
            a2.push(i);
         } else if(a1.size()) {
            int c = a1.top(); a1.pop();
            ans.pb(pii(p, pos[c])); ans.pb(pii(p, i));
            a2.push(i);
         } else fail();
         p --;
      }
   }
   printf("%d\n", (int)ans.size());
   for(pii x : ans) printf("%d %d\n", x.fs, x.sc);
   return 0;
}