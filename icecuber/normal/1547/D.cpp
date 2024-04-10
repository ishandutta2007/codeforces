#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int last = 0;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int y = ~x&last;
      cout << y << ' ';
      last = x^y;
    }
    cout << endl;
  }
}