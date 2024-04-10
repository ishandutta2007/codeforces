#include <bits/stdc++.h>
using namespace std;

const int MaxN = 100000;

int n;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  int res = INT_MAX, pos = 0;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;

    int cur = n * (x / n);
    if (x % n + 1 > i) {
      cur += n;
    }
    if (cur + i < res) {
      res = cur + i;
      pos = i;
    }
  }

  cout << pos << endl;

  return 0;
}