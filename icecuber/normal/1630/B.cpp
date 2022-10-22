#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    auto sorted = a;
    sort(sorted.begin(), sorted.end());
    array<int,2> best = {1,n};
    for (int l = 0; l < n; l++) {
      int r = (n+l*2+k +1)/2;
      if (r > n) break;
      int x = sorted[l], y = sorted[r-1];
      if (y-x < best[1]-best[0]) {
        best = {x,y};
      }
    }
    auto [x,y] = best;
    cout << x << ' ' << y << endl;
    int prv = 0, bal = 0;
    for (int i = 0; i < n; i++) {
      bal += (x <= a[i] && a[i] <= y)*2-1;
      if (bal == 1 && k > 1) {
        cout << prv+1 << ' ' << i+1 << endl;
        prv = i+1;
        bal = 0;
        k--;
      }
    }
    cout << prv+1 << ' ' << n << endl;
    //cout << endl;
  }
}