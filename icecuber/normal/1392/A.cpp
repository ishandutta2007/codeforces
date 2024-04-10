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
    set<int> s;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s.insert(a);
    }
    cout << (s.size() == 1 ? n : 1) << endl;
  }
}