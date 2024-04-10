#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      ll a;
      cin >> a;
      sum += a;
    }
    cout << (sum-1)/n+1 << endl;
  }
}