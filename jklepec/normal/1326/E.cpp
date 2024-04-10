#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define pb push_back
#define fi first
#define se second
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define TRACE(x) cerr << #x << "  " << x << endl
template<typename T1, typename T2>inline void minaj(T1 &x, T2 y) { x = (x > y ? y: x);}
template<typename T1, typename T2>inline void maxaj(T1 &x, T2 y) { x = (x < y ? y: x);}

typedef double lf;
typedef long long ll;
typedef pair<int, int> pii;

const int inf = 1e9;

const int mod = 1e9 + 7;
int add(int x, int y) {x += y; if(x >= mod) return x - mod; return x;}
int sub(int x, int y) {x -= y; if(x < 0) return x + mod; return x;}
int mul(int x, int y) {return (ll) x * y % mod;}

const int MAXN = 3e5 + 10;

int gdje[MAXN];
int p[MAXN];
int q[MAXN];

struct fen {
  int F[MAXN];
  int get(int x) {
    x += 5;
    int ret = 0;
    for(; x; x-= x & -x) ret += F[x];
    return ret;
  }
  void upd(int x) {
    x += 5;
    for(; x < MAXN; x += x & -x) F[x] ++;
  }
} A, B;

const int off = 1 << 19;

struct tour {
  int t[2 * off];
  int p[2 * off];

  void init() {
    REP(i, 2 * off) {
      t[i] = -inf;
    }
    REP(i, off) p[i + off] = -inf;
  }

  void upd(int x, int lo, int hi, int a, int b, int v) {
    if(lo >= a && hi <= b) {
      t[x] += v;
      p[x] += v;
      return;
    }
    if(lo >= b || hi <= a) return;
    int mi = (lo + hi) >> 1;
    upd(x * 2, lo, mi, a, b, v);
    upd(x * 2 + 1, mi, hi, a, b, v);

    t[x] = max(t[x * 2], t[x * 2 + 1]) + p[x];
  }
} T;

int sol[MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  REP(i, n) {
    cin >> p[i];
    gdje[p[i]] = i;
  }
  REP(i, n) {
    cin >> q[i];
    q[i] --;
  }

  T.upd(1, 0, off, 0, off - 1, -inf);

  int tmp = 0;
  for(int v = n; v; --v) {
    int i = gdje[v];
    T.upd(1, 0, off, i, i + 1, +inf);
    T.upd(1, 0, off, 0, i + 1, 1);


    /*int bomba = B.get(n + 1) - B.get(i - 1);
    int ljudi = A.get(n + 1) - A.get(i - 1);
    A.upd(i);
*/
    /*for(int x = (i + off) / 2; x; x /= 2) {
      T.t[x] = max(T.t[x * 2], T.t[x * 2 + 1]) + T.p[x];
    }*/

    int tmp_new = tmp;
    if(tmp == n) break;

    while(tmp_new < n - 1) {
      T.upd(1, 0, off, 0, q[tmp_new] + 1, -1);
      if(T.t[1] > 0) {
        tmp_new ++;
        B.upd(q[tmp_new]);
      } else {
        T.upd(1, 0, off, 0, q[tmp_new] + 1, +1);
        break;
      }
    }
    FOR(j, tmp, tmp_new) sol[j] = v;
    tmp = tmp_new;
  }

  cout << n << " ";
  REP(i, n - 1) cout << sol[i] << " ";
  cout << endl;

}