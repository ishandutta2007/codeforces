#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 2e5 + 10;
ll ans;
int n, a[maxn];

int dep, data[maxn], cpy[maxn];

int tot, ch[maxn * 15][2], sz[maxn * 15];

void ins(int x) {
  int cur = 0;
  per(i, dep, 0) {
    int &t = ch[cur][x >> i & 1];
    cur = t ? t : t = ++tot, ++sz[cur];
  }
}

int query(int x) {
  int cur = 0, res = 0;
  per(i, dep, 0) {
    int chk = x >> i & 1;
    if (sz[ch[cur][chk]]) {
      cur = ch[cur][chk];
    } else {
      cur = ch[cur][chk ^ 1], res |= 1 << i;
    }
  }
  return res;
}

void divide(int pos, int L, int R) {
  if (pos < 0 || L > R) return;
  int cnt[2];
  cnt[0] = cnt[1] = 0;
  rep(i, L, R) cnt[data[i] >> pos & 1]++;
  int now[2];
  now[0] = L, now[1] = L + cnt[0];
  rep(i, L, R) cpy[now[data[i] >> pos & 1]++] = data[i];
  rep(i, L, R) data[i] = cpy[i];
  if (!cnt[0] || !cnt[1]) {
    divide(pos - 1, L, L + cnt[0] - 1);
    divide(pos - 1, L + cnt[0], R);
    return;
  }
  dep = pos - 1;
  bool chk = cnt[0] > cnt[1];
  rep(i, L, R) if ((data[i] >> pos & 1) == chk) {
    ins(data[i] & ((1 << pos) - 1));
  }
  int res = INT_MAX;
  rep(i, L, R) if ((data[i] >> pos & 1) != chk) {
    chkmin(res, query(data[i] & ((1 << pos) - 1)));
  }
  ans += 1 << pos | res;
  rep(i, 0, tot) ch[i][0] = ch[i][1] = sz[i] = 0;
  tot = 0;
  divide(pos - 1, L, L + cnt[0] - 1);
  divide(pos - 1, L + cnt[0], R);
}

int main() {
  cin >> n;
  rep(i, 1, n) a[i] = read();
  memcpy(data, a, sizeof data);
  divide(29, 1, n);
  cout << ans;
  return 0;
}