#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      sum += v;
    }
    cout << (sum%n != 0) << endl;
  }
}