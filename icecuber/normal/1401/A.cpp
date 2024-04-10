#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int A, k;
    cin >> A >> k;
    if (A < k) cout << k-A << endl;
    else cout << (A+k)%2 << endl;
  }
}