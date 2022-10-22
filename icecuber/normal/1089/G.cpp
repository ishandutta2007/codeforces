#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int a[7], p[8] = {};
    int s = 0;
    for (int i = 0; i < 7; i++) {
      cin >> a[i];
      s += a[i];
      p[i+1] = s;
    }
    int best = 1e9;
    for (int i = 0; i < 7; i++) {
      int v = (k-s)/s*7;
      int j = i;
      int left = (k-s)%s+s;
      while (left) {
	left -= a[j%7];
	j++, v++;
      }
      best = min(best, v);
    }
    cout << best << endl;
  }
}