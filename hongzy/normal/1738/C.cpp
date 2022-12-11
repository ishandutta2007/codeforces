#include <bits/stdc++.h>
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
mt19937 mt(std::chrono::system_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> ran(0, 1ll << 62);
void ucin() { ios::sync_with_stdio(0); cin.tie(0); }
// uniform_real_distribution<double> dbran;
template<class T> inline void chkmax(T &x, const T &y) { if(x < y) x = y; }
template<class T> inline void chkmin(T &x, const T &y) { if(x > y) x = y; }
inline ll sqr(ll x) { return x * x; }
inline ll cub(ll x) { return x * x * x; }

const int N = 100 + 5;
const int mod = 1e9 + 7;
int n, c0, c1;
bool A[2][N][N], B[2][N][N]; //1: Alice win
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d", &n);
    c0 = c1 = 0;
    rep(i, 1, n) {
      int x;
      scanf("%d", &x);
      x &= 1;
      if(x) c1 ++;
      else c0 ++;
    }
    // printf("%d %d\n", c0, c1);
    memset(A, 0, sizeof A);
    memset(B, 0, sizeof B);
    A[0][0][0] = 1; A[1][0][0] = 0;
    B[0][0][0] = 1; B[1][0][0] = 0;
    rep(i, 0, c0) rep(j, 0, c1) rep(v, 0, 1) {
      if(i || j) {
        A[v][i][j] = 0;
        if(i > 0 && B[v][i-1][j])
          A[v][i][j] = 1;
        else if(j > 0 && B[v^1][i][j-1])
          A[v][i][j] = 1;

        B[v][i][j] = 1;
        if(i > 0 && !A[v][i-1][j])
          B[v][i][j] = 0;
        else if(j > 0 && !A[v][i][j-1])
          B[v][i][j] = 0;
        // printf("A[%d][%d][%d] = %d\n", v, i, j, A[v][i][j]);
      }
    }
    puts(A[0][c0][c1] ? "Alice" : "Bob");
  }
  return 0;
}