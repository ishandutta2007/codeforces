// Hydro submission #626de067e219e5653b8ee388@1651368039537
// 
// 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, l, r) for(int i = (l); i <= r; ++i)
#define REP(i, l, r) for(int i = (l); i <  r; ++i)
#define DFR(i, l, r) for(int i = (l); i >= r; --i)
#define DRP(i, l, r) for(int i = (l); i >  r; --i)
#define FORV(i, ver) for(int i = 0; i < ver.size(); i++)
#define FORP(i, ver) for(auto i : ver)
template<class T>T wmin(const T &a, const T &b) {return a < b ? a : b;}
template<class T>T wmax(const T &a, const T &b) {return a > b ? a : b;}
template<class T>bool chkmin(T &a, const T &b) {return a > b ? a = b, 1 : 0;}
template<class T>bool chkmax(T &a, const T &b) {return a < b ? a = b, 1 : 0;}
inline int read() {
  int x = 0, f = 1;  char ch = getchar();
  while( !isdigit(ch) ) { if(ch == '-') f = -1;  ch = getchar();  }
  while( isdigit(ch) ) {  x = (x << 1) + (x << 3) + (ch ^ 48);  ch = getchar();  }
  return x * f;
}
const int N = 1e6 + 6;
struct node { int op, x, y, tx, ty; } a[N], b[N];
struct Segment { int tim, pos, val; }cg[N], ak[N];
int n, m, tot, cnt, ans;
class BIT {
  public: int c[N];
  public: int lowbit(int x) { return x & (-x); }
  public: void change(int x,int val) { for (int i = x; i < N; i += lowbit(i)) c[i] += val; }
  public: int ask(int x) { int ans = 0; for (int i = x; i; i -= lowbit(i)) ans += c[i]; return ans; }
  public: void clear() { memset(c, 0, sizeof(c)); }
}c;
signed main () {
  n = read(), m = read();
  FOR (i, 1, n) 
    a[i].op = 1, a[i].y = read() + 1, a[i].tx = read() + 1, a[i].ty = read() + 1;
  FOR (i, 1, m) 
    b[i].op = -1, b[i].x = read() + 1, b[i].tx = read() + 1, b[i].ty = read() + 1;
  int j = 1, ans = 1, pt = 1;
  FOR (i, 1, n) 
    if (a[i].tx == 1 && a[i].ty == 1e6 + 1) ans++;
  FOR (i, 1, m) 
    if (b[i].tx == 1 && b[i].ty == 1e6 + 1) ans++;
  FOR (i, 1, n) 
    cg[++tot] = {a[i].tx - 1, a[i].y, 1}, cg[++tot] = {a[i].ty, a[i].y, -1};
  FOR (i, 1, m) 
    ak[i] = {b[i].x, b[i].tx, b[i].ty};
  sort(cg + 1, cg + tot + 1, [](Segment x, Segment y) { return x.tim < y.tim; } );
  sort(ak + 1, ak + m + 1, [](Segment x, Segment y) { return x.tim < y.tim; });
  while (cg[j].tim = 0 && j <= tot)
    c.change(cg[j].pos, cg[j].val), j++;
  REP (i, 1, N) {
    while (pt <= m && ak[pt].tim <= i)
      ans += c.ask(ak[pt].val) - c.ask(ak[pt].pos - 1), pt++;
    while (j <= tot && cg[j].tim <= i) 
      c.change(cg[j].pos, cg[j].val), ++j;
  }
  printf("%lld\n", ans);
  return 0;
}
/*

[1][2]
[2] 
[1] 


*2400
3 1 6
4 2 1000001
5 1 2
7

*/