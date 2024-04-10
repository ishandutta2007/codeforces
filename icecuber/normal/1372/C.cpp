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
    vector<int> p(n);
    for (int&v : p) cin >> v, v--;
    int oks = 0, first = n, last = -1;
    for (int i = 0; i < n; i++) {
      oks += (p[i] == i);
      if (p[i] != i) {
	first = min(first, i);
	last = max(last, i);
      }
    }
    if (oks == n) cout << 0 << endl;
    else if (oks+last-first+1 == n) cout << 1 << endl;
    else cout << 2 << endl;
  }
}