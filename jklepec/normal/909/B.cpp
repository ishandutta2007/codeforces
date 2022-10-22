#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 105;

int a[MAXN];

int main() {
  int n; cin >> n;
  REP(i, n) FOR(j, i + 1, n + 1) {
    FOR(k, i, j) a[k] ++;
  }
  int mx = 0;

  REP(i, n) mx = max(mx, a[i]);

  cout << mx;
}