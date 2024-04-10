// Hydro submission #62419f63b4d87d0be1e29117@1648467811830
// 
// 
#include <bits/stdc++.h>
#define int long long
using namespace std;
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
const int N = 2e6;
int n, vis[N], pr[N], tot, c[N], num;
void prime(int n) {
  FOR (i, 2, n) {
    if (vis[i]) continue;
    pr[++tot] = i;
    for (int j = i; j <= n; j += i) vis[j] = 1;
  }
}
int A(int x) {
  cout << "A " << x << "\n";  cout.flush();
  int qwq;  cin >> qwq;  return qwq;
}
void B(int x) {
  cout << "B " << x << "\n";  cout.flush();
  int qwq;  cin >> qwq;
}
void C(int x) {
  cout << "C " << x << "\n";  cout.flush();  exit(0);
}
signed main () {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  n = read(); prime(n);
  if (n == 1) { C(1); }
  int now = 1;
  FOR (i, 1, tot) {
    if (pr[i] > 316) break;
    int x = pr[i];
    B(x);
    if ( A(x) == 1 ) {
      now = now * x;
      int gtr = x;
      while (1) {
        gtr *= x;
        if (gtr > n) break;
        if ( A(gtr) == 1 ) now *= x;
        else break;
      }
    }
  }
  if (now == 1) {
    int ans = 1;
    FOR (i, 1, tot) {
      if (pr[i] < 316) continue;
      c[++num] = pr[i];
    }
    int siz = 86, bel = (num - 1) / siz + 1;
    int cnt = A(1);
    FOR (i, 1, bel) {
      int l = (i - 1) * siz + 1;
      int r = wmin(num, i * siz);
      int len = r - l + 1;
      FOR (j, l, r) {
        int x = c[j];
        B(x);
      }
      int qaq = A(1);
      if (qaq == cnt - len) { cnt -= len;  continue;  }
      FOR (j, l, r) {
        int x = c[j];
        int qwq = A(x);
        if (qwq) C(x);
      }
    }
    C(1);
  }
  FOR (i, 1, tot) {
    if (pr[i] < 316) continue;
    int x = pr[i];
    if (x * now > n) break;
    if (A(x * now) == 1) C(x * now);
  }
  C(now);
  return 0;
}
/*
?1e5 10000 ?
 1e5  9592 ?
*/