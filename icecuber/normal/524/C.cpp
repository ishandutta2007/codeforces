#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  int q;
  cin >> q;
  while (q--) {
    int target;
    cin >> target;
    int need = 1e9;
    for (int i = 0; i < n; i++) {
      for (int x = 0; x <= k; x++) {
	int left = target-x*a[i];
	if (left == 0) {
	  need = min(need, x);
	}
	for (int y = 1; x+y <= k; y++) {
	  if (left%y) continue;
	  if (binary_search(a.begin(), a.end(), left/y)) {
	    need = min(need, x+y);
	  }
	}
      }
    }
    if (need == 1e9) need = -1;
    cout << need << endl;
  }
}