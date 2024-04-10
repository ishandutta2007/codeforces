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
    vector<array<int,2>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0];
      a[i][1] = i;
    }
    sort(a.begin(), a.end());
    cout << a[0][1]+1 << ' ' << a.back()[1]+1 << endl;
  }
}