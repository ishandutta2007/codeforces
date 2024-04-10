#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int m = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i && a[i] != a[i-1]) m++;
    }
    if (k == 1)
      cout << (m ? -1 : 1) << endl;
    else
      cout << max((m+k-2)/(k-1),1) << endl;
  }
}