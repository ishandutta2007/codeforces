#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int g = 0;
  for (int&v : a) {
    cin >> v;
    g = __gcd(g, v);
  }
  if (g > 1) {
    cout << -1 << endl;
    return 0;
  }
  int ones = count(a.begin(), a.end(), 1);
  if (ones) {
    cout << n-ones << endl;
    return 0;
  }
  int mi = n;
  for (int i = 0; i < n; i++) {
    int g = 0;
    for (int j = i; j < n; j++) {
      g = __gcd(g, a[j]);
      if (g == 1) {
	mi = min(mi, j-i);
	break;
      }
    }
  }
  cout << n-1+mi << endl;
}