#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 5e3 + 5;

int a[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, m; cin >> n >> m;

  REP(i, n) {
    string s; cin >> s;
    for(int j = m - 1, len = 1; j >= 0; j --) {
      if(s[j] == '0') {
        len = 0;
      }
      a[j][len ++] ++;
    }
  }

  int sol = 0;

  REP(j, m) {
    int tmp = 0;
    for(int i = MAXN - 1; i; --i) {
      tmp += a[j][i];
      sol = max(sol, tmp * i);
    }
  }
  cout << sol;
}