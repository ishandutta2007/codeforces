#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[300000][8];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> a[i][j];
  int pass = -1, fail = 1e9+1;
  int ind1 = -1, ind2 = -1;
  while (fail-pass > 1) {
    int mid = pass+fail>>1;
    //cout << pass << ' ' << fail << ' ' << mid << endl;
    vector<int> has(1<<m), ind(1<<m);
    for (int i = 0; i < n; i++) {
      int mask = 0;
      for (int j = 0; j < m; j++) {
	mask |= (a[i][j] >= mid)<<j;
      }
      has[mask] = 1;
      ind[mask] = i;
    }
    int ok = 0;
    for (int i = 0; i < 1<<m; i++)
      for (int j = 0; j < 1<<m; j++) {
	if ((i|j) == (1<<m)-1 && has[i] && has[j]) {
	  ind1 = ind[i];
	  ind2 = ind[j];
	  ok = 1;
	}
      }
    if (ok) {
      pass = mid;
    } else fail = mid;
  }
  cout << ind1+1 << ' ' << ind2+1 << endl;
}