#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  string a, b;
  cin >> a >> b;
  if (count(a.begin(), a.end(), '1') !=
      count(b.begin(), b.end(), '1')) {
    cout << -1 << endl;
    return 0;
  }
  int zeros = 0, ones = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '0' && b[i] == '1') {
      if (ones) ones--;
      zeros++;
    }
    if (a[i] == '1' && b[i] == '0') {
      if (zeros) zeros--;
      ones++;
    }
  }
  cout << ones+zeros << endl;
}