#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[1000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  fill_n(ans, n, 1e9);
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 2; j++) {
      vector<int> q;
      for (int k = 0; k < n; k++) {
	if ((k>>i&1) == j)
	  q.push_back(k);
      }
      if (q.empty()) continue;
      cout << q.size() << endl;
      for (int i : q)
	cout << i+1 << ' ';
      cout << endl;
      for (int k = 0; k < n; k++) {
	int response;
	cin >> response;
	if ((k>>i&1) != j)
	  ans[k] = min(ans[k], response);
      }
    }
  }
  cout << -1 << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i] << ' ';
  cout << endl;
}