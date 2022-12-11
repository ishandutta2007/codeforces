#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
char gc() {
  static char buf[1 << 17], *S, *T;
  if(S == T) T = (S = buf) + fread(buf, 1, 1 << 17, stdin);
  return S == T ? EOF : *S ++;
}
template<class T> void read(T &x) {
  x = 0; char c = gc(); bool na = 0;
  for(; c < '0' || c > '9'; c = gc()) na |= c == '-';
  for(; c >= '0' && c <= '9'; c = gc()) x = x * 10 + (c & 15);
  if(na) x = -x;
}
typedef unsigned long long ull;
const int N = 1024;
struct Bitset {
  vector<ull> a;
  void resize(int n) { a.resize((n >> 6) + 2); }
  bool operator [](int x) const { return a[x >> 6] >> (x & 63) & 1; }
  void set(int x) { a[x >> 6] |= 1ull << (x & 63); }
  void reset(int x) { a[x >> 6] &= ~(1ull << (x & 63)); }
  void flip(int x) { a[x >> 6] ^= 1ull << (x & 63); }
  Bitset operator ^ (const Bitset &b) {
    Bitset ans = b;
    for(int i = 0; i < (int)a.size(); i ++) ans.a[i] ^= a[i];
    return ans;
  }
  Bitset operator | (const Bitset &b) {
    Bitset ans = b;
    for(int i = 0; i < (int)a.size(); i ++) ans.a[i] |= a[i];
    return ans;
  }
  Bitset operator & (const Bitset &b) {
    Bitset ans = b;
    for(int i = 0; i < (int)a.size(); i ++) ans.a[i] &= a[i];
    return ans;
  }
  int find_first() {
    for(int i = 0; i < (int)a.size(); i ++)
      if(a[i]) return i << 6 | __builtin_ctzll(a[i]);
    return -1;
  }
  int find_next(int x) {
    ull t;
    int z = (x & 63) < 63 && (t = a[x >> 6] & ~((1ull << ((x & 63) + 1)) - 1)) ? __builtin_ctzll(t) : 0;
    if(z) return ((x >> 6) << 6) | z;
    for(int i = (x >> 6) + 1; i < (int)a.size(); i ++)
      if(a[i]) return i << 6 | __builtin_ctzll(a[i]);
    return -1;
  }
  int count() {
    int z = 0;
    for(int i = 0; i < (int)a.size(); i ++)
      if(a[i]) z += __builtin_popcountll(a[i]);
    return z;
  }
  bool operator == (const Bitset &b) const {
    for(int i = 0; i < (int)a.size(); i ++)
      if(a[i] != b.a[i]) return 0;
    return 1;
  }
} a[N], res, b[N];
struct node {
  int x, y;
};
vector<node> edge;
int n, s[N];
bool isf[N];
bool ok(const Bitset &a, const Bitset &b, Bitset &res) {
  res = b;
  int c = 0;
  for(int i = 0; i < (int)a.a.size(); i ++) {
    if((res.a[i] &= a.a[i]) > 0) {
      c += __builtin_popcountll(res.a[i]);
      if(c >= 3) break ;
    }
  }
  return c == 2;
}
int main() {
  read(n);
  if(n == 2) { puts("1 2"); return 0; }
  rep(i, 1, n) {
    a[i].resize(n + 1);
    b[i].resize(n + 1);
    b[i].set(i);
    int sz, u; read(sz);
    rep(j, 1, sz) {
      read(u); a[i].set(u);
    }
    s[i] = sz;
  }
  rep(i, 1, n) rep(j, i + 1, n) {
    if(!ok(a[i], a[j], res)) continue ;
    int x = res.find_first(), y = res.find_next(x);
    if(b[x][y]) continue ;
    b[x].set(y); b[y].set(x);
    edge.pb({x, y});
    isf[x] = isf[y] = 1;
  }
  int cnt = 0;
  rep(i, 1, n) cnt += isf[i] > 0;
  if(cnt == 0) {
    rep(i, 2, n) printf("1 %d\n", i);
    return 0;
  }
  if(cnt == 2) {
    int u = 0, v = 0;
    rep(i, 1, n) if(isf[i]) (u ? v : u) = i;
    rep(i, 1, n) if(s[i] < n) {
      printf("%d %d\n", u, v);
      rep(j, 1, n) if(j != u && j != v) {
        printf("%d %d\n", a[i][j] ? u : v, j);
      }
      break ;
    }
    return 0;
  }
  static int p[N];
  rep(i, 1, n) p[i] = i;
  sort(p + 1, p + n + 1, [&](int x, int y) { return s[x] < s[y]; });
  rep(i, 1, n) if(!isf[i]) {
    int id = 0;
    rep(j, 1, n) if(p[j] && a[p[j]][i]) { id = p[j]; p[j] = 0; break ; }
    rep(j, 1, n) if(!isf[j]) a[id].reset(j);
    rep(j, 1, n) if(isf[j] && b[j] == a[id]) {
      edge.pb({i, j});
      break ;
    }
  }
  for(node k : edge) {
    printf("%d %d\n", k.x, k.y);
  }
  return 0;
}
/*
11
7 1 2 3 4 5 6 7
9 1 2 3 4 5 8 9 10 11
5 1 2 3 6 7
6 1 2 5 4 8 9
6 1 2 5 4 10 11
4 1 3 6 7
4 1 3 6 7
4 2 4 8 9
4 2 4 8 9
4 2 5 10 11
4 2 5 10 11
*/