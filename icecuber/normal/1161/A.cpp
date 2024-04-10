#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int first[100000], last[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) first[i] = q, last[i] = -1;
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    x--;
    if (first[x] == q)
      first[x] = i;
    last[x] = i;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j : {i-1,i,i+1}) {
      if (j < 0 || j >= n) continue;
      ans += first[i] > last[j];
    }
  }
  cout << ans << endl;
}