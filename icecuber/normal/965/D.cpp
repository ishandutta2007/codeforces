#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, l;
  cin >> n >> l;
  vector<int> a(n+1);
  a[0] = 2e9;
  int j = 0;
  for (int i = 1; i <= n; i++) {
    int c;
    if (i < n)
      cin >> c;
    else c = 1e9;
    while (i-j > l) j++;
    while (j < i && c) {
      int x = min(a[j], c);
      c -= x;
      a[j] -= x;
      a[i] += x;
      if (!a[j]) j++;
    }
  }
  cout << a[n] << endl;
}