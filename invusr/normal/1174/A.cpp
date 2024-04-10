#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n * 2);
  for (int i = 0; i < n * 2; ++i) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    sum += a[i] - a[n * 2 - i - 1];
  }
  if (!sum) {
    cout << "-1\n";
  } else {
    for (int i : a) {
      cout << i << ' ';
    }
  }

  return 0;
}