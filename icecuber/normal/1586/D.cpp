#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans(n);
  for (int d = 1-n; d <= n-1; d++) {
    int A, B;
    if (d > 0) A = 1, B = 1+d;
    else B = 1, A = 1-d;

    cout << "?";
    for (int i = 0; i < n-1; i++) cout << ' ' << A;
    cout << ' ' << B << endl;
    int k;
    cin >> k;
    if (k) ans[k-1] = B-A;
  }
  int off = 1-*min_element(ans.begin(), ans.end());
  for (int&v : ans) v += off;
  cout << "!";
  for (int v : ans) cout << ' ' << v;
  cout << endl;
}