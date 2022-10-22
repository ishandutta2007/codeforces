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
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      sum += k-1;
    }
    cout << (sum%2 ? "errorgorn" : "maomao90") << endl;
  }
}