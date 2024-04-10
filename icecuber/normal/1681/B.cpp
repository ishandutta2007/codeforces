#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    ll sum = 0;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
      int v;
      cin >> v;
      sum = (sum+v)%n;
    }
    cout << a[sum] << endl;
  }
}