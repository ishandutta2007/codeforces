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
    sort(a.begin(), a.end());
    int mindiff = 1e9;
    for (int i = 0; i+1 < n; i++) {
      mindiff = min(mindiff, a[i+1]-a[i]);
    }
    cout << mindiff << endl;
  }
}