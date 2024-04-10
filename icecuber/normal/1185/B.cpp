#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a >> b;
    int ai = 0, bi = 0;
    while (1) {
      if (a[ai] != b[bi]) goto fail;
      int aj = ai, bj = bi;
      while (aj < a.size() && a[aj] == a[ai]) aj++;
      while (bj < b.size() && b[bj] == b[bi]) bj++;
      if (bj-bi < aj-ai) goto fail;
      ai = aj;
      bi = bj;
      if (ai == a.size() || bi == b.size()) break;
    }
    if (ai != a.size() || bi != b.size()) goto fail;
    cout << "YES" << endl;
    continue;
  fail:
    cout << "NO" << endl;
  }
}