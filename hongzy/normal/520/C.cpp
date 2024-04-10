#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef double db;
typedef long long ll;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int n, D[N], fav[N], fac[N];
ll ans, cur, cnt, ccnt, c[N];
char s[N];
int C(int n, int m) {
   return n < m ? 0 : 1ll * fac[n] * fav[m] % mod * fav[n - m] % mod;
}
int qpow(int a, int b) {
   int ans = 1;
   for(; b >= 1; b >>= 1, a = 1ll * a * a % mod)
      if(b & 1) ans = 1ll * ans * a % mod;
   return ans;
}
void binom(int n) {
   fac[0] = 1;
   for(int i = 1; i <= n; i ++) fac[i] = 1ll * fac[i - 1] * i % mod;
   fav[n] = qpow(fac[n], mod - 2);
   for(int i = n; i >= 1; i --) fav[i - 1] = 1ll * fav[i] * i % mod;
}
int main() {
   D['A'] = 4; D['T'] = 1; D['C'] = 2; D['G'] = 3;
   scanf("%d%s", &n, s + 1);
   rep(i, 1, n) c[D[s[i]]] ++;
   sort(c + 1, c + 4 + 1);
   //binom(n);
   int y = *max_element(c + 1, c + 5), z = 0;
   rep(i, 1, 4) z += c[i] == y;
   printf("%d\n", (int) qpow(z, n));
   return 0;
}