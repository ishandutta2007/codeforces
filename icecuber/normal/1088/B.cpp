#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  set<int> s;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s.insert(a);
  }
  int last = 0;
  while (k--) {
    if (s.empty()) cout << 0 << '\n';
    else {
      int t = *s.begin();
      s.erase(t);
      cout << t-last << '\n';
      last = t;
    }
  }
}