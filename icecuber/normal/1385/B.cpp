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
    set<int> seen;
    for (int i = 0; i < n*2; i++) {
      int p;
      cin >> p;
      if (seen.insert(p).second) cout << p << ' ';
    }
    cout << endl;
  }
}