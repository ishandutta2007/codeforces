#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i) a[i] ^= a[i-1];
  }
  if (!a[n-1]) {
    cout << -1 << endl;
    return 0;
  }
  vector<int> subset, mask;
  for (int i = n-1; i >= 0; i--) {
    int m = a[i];
    for (int j = 0; j < subset.size(); j++)
      if (m&mask[j]) m ^= subset[j];
    if (m) {
      int bit = m&-m;
      mask.push_back(bit);
      for (int&j : subset)
	if (j&bit) j ^= m;
      subset.push_back(m);
    }
  }
  cout << subset.size() << endl;
}