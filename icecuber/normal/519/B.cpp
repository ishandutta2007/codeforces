#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int h[3] = {};
  for (int k = 0; k < 3; k++) {
    for (int i = 0; i < n-k; i++) {
      int a;
      cin >> a;
      h[k] ^= a;
    }
  }
  cout << (h[1]^h[0]) << ' ' << (h[2]^h[1]) << endl;
}