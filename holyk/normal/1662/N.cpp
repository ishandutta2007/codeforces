#include <bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define fo(i, a, b) for(int i = a; i <= b; i++)
#define pii pair<int, int>
using namespace std;
const int N = 1600;

struct Bit {
  int n, s[N * N];

  int lowbit(int x) {return x & -x;}
  void cg(int x, int c) {for(int i = x; i <= n; i += lowbit(i)) s[i] += c;}
  int getsum(int x) {int sum = 0; for(int i = x; i; i -= lowbit(i)) sum += s[i]; return sum;}
} s;
int a[N][N];
int n, r1[N][N], r2[N][N], l1[N][N], l2[N][N];

void solve() {
  cin >> n;
  s.n = n * n;
  LL ans = 0;
  fo(i, 1, n) fo(j, 1, n) cin >> a[i][j];
  
  fo(i, 1, n) {
    fo(j, 1, n) s.cg(a[i][j], 1);
    fo(j, 1, n) l1[i][j] = s.getsum(a[i][j] - 1), l2[i][j] = n - s.getsum(a[i][j]);
    fo(j, 1, n) s.cg(a[i][j], -1);
  }
  fo(j, 1, n) {
    fo(i, 1, n) s.cg(a[i][j], 1);
    fo(i, 1, n) r1[i][j] = s.getsum(a[i][j] - 1), r2[i][j] = n - s.getsum(a[i][j]);
    fo(i, 1, n) s.cg(a[i][j], -1);
  }
  /*
  fo(i, 1, n) fo(j, 1, n) {
    cout << l1[i][j] << ' ' << l2[i][j] << ' ' << r1[i][j] << ' ' << r2[i][j] << '\n';
  }
  */
  fo(i, 1, n) fo(j, 1, n) ans += (LL)l1[i][j] * r2[i][j] + (LL)l2[i][j] * r1[i][j];
  cout << ans / 2 << '\n';
}

int main(){
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int T = 1;
  while(T--) {
    solve();
  }
  return 0;
}