#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<
#define sz(x) ((int) x.size())
#define pb push_back

typedef long long ll;
typedef pair<int, int> point;

const int mod = 998244353;

int add(int x, int y) {
  x += y;
  if(x >= mod) return x - mod;
  return x;
}
int mul(int x, int y) {
  return (ll) x * y % mod;
}

int sub(int x, int y) {
  x -= y;
  if(x < 0) return x + mod;
  return x;
}


int a[100005];
int mem[100005][205][2];
int pref[100005][205][2];

int dp(int n, int k, int need) {
  if(a[n] != -1 && a[n] != k) {
    return 0;
  }

  if(n == 0) {
    if(need) return 0;
    if(a[n] == -1 || a[n] == k) return 1;
  }

  if(mem[n][k][need] != -1) return mem[n][k][need];

  int ret = 0;
  FOR(i, 1, 200 + 1) {
    if(!need || i >= k) {
      int nn = 0;
      if(i > k) nn = 1;
      ret = add(ret, dp(n - 1, i, nn));
    }
  }

  return mem[n][k][need] = ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;

  REP(i, n) cin >> a[i];

  REP(i, n) {
    FOR(j, 1, 201) REP(k, 2) {
      if(a[i] != -1 && a[i] != j) {
        continue;
      }
      if(i == 0) {if(!k && (a[i] == -1 || a[i] == j)) mem[i][j][k] = 1;}
      else {
        if(!k) {
          mem[i][j][k] = add(pref[i - 1][200][1], pref[i - 1][j][0]);
          mem[i][j][k] = sub(mem[i][j][k], pref[i - 1][j][1]);
        }
        else {
          mem[i][j][k] = add(pref[i - 1][200][1], pref[i - 1][j][0]);
          mem[i][j][k] = sub(mem[i][j][k], add(pref[i - 1][j - 1][0], pref[i - 1][j][1]));
        }
      }
    }

    FOR(j, 1, 201) REP(k, 2) pref[i][j][k] = add(pref[i][j - 1][k], mem[i][j][k]);
  }

  cout << pref[n - 1][200][1] << endl;
}