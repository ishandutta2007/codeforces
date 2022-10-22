#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int n;
string ans, str[maxn];

typedef pair <int, int> pii;
const int P1 = 1e9 + 7, P2 = 1e9 + 9;
int base, pow1[maxn], pow2[maxn];

struct Hash {
  int v1, v2;
  
  Hash() {}
  Hash(int x, int y) : v1(x), v2(y) {}
  
  inline void print() {
    printf("#(%d %d)\n", v1, v2);
  }
  
  void get(Hash &o, char ch) {
    v1 = (1ll * o.v1 * base + ch) % P1;
    v2 = (1ll * o.v2 * base + ch) % P2;
  }
  
  inline bool operator == (const Hash &o) const {
    return v1 == o.v1 && v2 == o.v2;
  }
} val[maxn], sum[maxn];

Hash getsum(Hash *a, int l, int r) {
  return Hash((a[r].v1 - 1ll * a[l - 1].v1 * pow1[r - l + 1] % P1 + P1) % P1,
              (a[r].v2 - 1ll * a[l - 1].v2 * pow2[r - l + 1] % P2 + P2) % P2);
}

int calc(int pos) {
  int sz = ans.size();
  int len = min(sz, (int) str[pos].size());
  for (int i = 1; i <= len; i++) {
    sum[i].get(sum[i - 1], str[pos][i - 1]);
  }
  for (int i = len; i; i--) {
    if (getsum(val, sz - i + 1, sz) == getsum(sum, 1, i)) {
      return i;
    }
  }
  return 0;
}

int main() {
  srand(time(0));
  srand(rand() << 15 | rand());
  srand(rand() << 15 | rand());
  srand(rand() << 15 | rand());
  base = (rand() << 15 | rand()) % 19260817 + 257;
  pow1[0] = pow2[0] = 1;
  for (int i = 1; i < maxn; i++) {
    pow1[i] = 1ll * base * pow1[i - 1] % P1;
    pow2[i] = 1ll * base * pow2[i - 1] % P2;
  }
  cin.tie(0), cout.tie(0);
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> str[i];
  }
  ans = str[1];
  for (int i = 0; i < (int) ans.size(); i++) {
    val[i + 1].get(val[i], ans[i]);
  }
  for (int i = 2; i <= n; i++) {
    int pos = calc(i), sz = str[i].size();
    if (pos == sz) continue;
    string tmp = str[i].substr(pos, sz);
    for (char c : tmp) {
      ans += c;
      int p = ans.size();
      val[p].get(val[p - 1], c);
    }
  }
  cout << ans << endl;
  return 0;
}