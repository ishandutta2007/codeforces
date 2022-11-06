#include <bits/stdc++.h>

#define LL long long
#define fi first
#define se second
#define fo(i, a, b) for(int i = a; i <= b; i++)
#define pii pair<int, int>
using namespace std;
const int N = 210, mod = 998244353;
int nn, d[N];

bool v[N][N];

struct mat {
  int a[N][N];

  mat() {memset(a, 0, sizeof(a));}
  friend mat operator * (const mat &a, const mat &b) {
    mat c;
    fo(i, 1, nn) fo(j, 1, nn) fo(k, 1, nn) {
      c.a[i][j] = (c.a[i][j] + (LL)a.a[i][k] * b.a[k][j]) % mod;
    } return c;
  }
} ans;


void solve() {
  int n, m, k;
  cin >> n >> m >> k; nn = n * 2;
  fo(i, 1, m) {
    int x, y; cin >> x >> y;
    v[x][y] = v[y][x] = 1;
    d[x]++, d[y]++;
  }
  fo(i, 1, n) {
    ans.a[i][i + n] = (mod - d[i] + 1) % mod;
    ans.a[i + n][i] = 1;
    fo(j, 1, n) if(v[i][j]){
      ans.a[i + n][j + n] = 1;
    }
  }
  k--;
  mat s;
  fo(i, 1, nn) s.a[i][i] = 1;
  while(k) {
    if(k & 1) s = ans * s;
    ans = ans * ans, k >>= 1;
  }
  int sum = 0;
  fo(i, 1, n) {
    sum = (sum + (LL)s.a[i + n][i] * (mod - d[i])) % mod;
    fo(j, 1, n) if(v[i][j]){
      sum = (sum + s.a[i + n][j + n]) % mod;
    }
  }
  cout << sum << '\n';
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