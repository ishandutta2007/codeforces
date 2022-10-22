#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[101];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int k = 0; k < n; k++) {
    int t;
    cin >> t;
    int rem = m-t, pass = 0;
    for (int i = 0; i <= 100; i++) {
      int need = c[i]*i;
      if (need > rem || i == 100) {
	pass += min(rem/i, c[i]);
	cout << k-pass << ' ';
	break;
      }
      pass += c[i];
      rem -= need;
    }
    c[t]++;
  }
  cout << endl;
}