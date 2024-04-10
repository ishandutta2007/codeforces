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
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int ma = *max_element(a.begin(), a.end());

    int ans = -1;
    for (int i = 0; i < n; i++) {
      if (a[i] == ma && ((i && a[i] > a[i-1]) || (i+1 < n && a[i] > a[i+1])))
	ans = i+1;
    }
    cout << ans << endl;
  }
}