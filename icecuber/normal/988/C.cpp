#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int, pair<int,int>> m;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> a(k);
    int sum = 0;
    for (int j = 0; j < k; j++) {
      cin >> a[j];
      sum += a[j];
    }
    for (int j = 0; j < k; j++) {
      int v = sum-a[j];
      if (m.count(sum-a[j])) {
	cout << "YES" << endl;
	cout << m[v].first+1 << ' ' << m[v].second+1 << endl;
	cout << i+1 << ' ' << j+1 << endl;
	return 0;
      }
    }
    for (int j = 0; j < k; j++) {
      m[sum-a[j]] = {i, j};
    }
  }
  cout << "NO" << endl;
}