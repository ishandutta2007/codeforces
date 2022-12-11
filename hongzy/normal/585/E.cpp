#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
const int M = 1e7 + 10;
const int mod = 1e9 + 7;
int n, m, pw[N], a[N], c[M], num[1 << 8], lg[1 << 8];
int mp[M], p[M], pc, mu[M];
bool tag[M];
void sieve(int n) {
  rep(i, 2, n) {
    if(!tag[i]) p[++ pc] = i, mp[i] = pc, mu[i] = -1;
    rep(j, 1, mp[i]) {
      int v = i * p[j];
      if(v > n) break ;
      tag[v] = 1;
      mp[v] = j;
      if(j != mp[i]) mu[v] = -mu[i];
    }
  }
}
int main() {
  rep(i, 0, 7) lg[1 << i] = i;
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i), m = max(m, a[i]), ++ c[a[i]];
  sieve(m);
  rep(i, 1, pc) per(j, m / p[i], 1) c[j] += c[j * p[i]];
  pw[0] = 1;
  rep(i, 1, n) pw[i] = pw[i - 1] * 2 % mod;
  int ans = 0;
  rep(i, 2, m) if(c[i] && mu[i]) ans = (ans - mu[i] * (pw[c[i]] - 1ll)) % mod;
  ans = (ll)ans * n % mod;
  vector<int> S;
  rep(i, 1, n) {
    S.clear();
    int z = a[i];
    for(; z > 1; z /= p[mp[z]])
      S.pb(p[mp[z]]);
    S.resize(unique(S.begin(), S.end()) - S.begin());
    int sz = int(S.size());
    num[0] = 1;
    for(int s = 1; s < (1 << sz); s ++) {
      int t = s & (s - 1);
      num[s] = num[t] * S[lg[s ^ t]];
      ans = (ans + mu[num[s]] * (pw[c[num[s]]] - 1ll)) % mod;
    }
  }
  ans += ans < 0 ? mod : 0;
  printf("%d\n", ans);
  return 0;
}