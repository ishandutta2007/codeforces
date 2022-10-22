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
    auto cp = a;
    for (int i = 0; i < n; i++) cp[i] *= -1;
    cout << n/2*6 << endl;
    for (int i = 0; i < n; i += 2) {
      for (int t : {2,1,2,2,1,2}) {
        cout << t << ' ' << i+1 << ' ' << i+2 << endl;
        if (t == 1) a[i] += a[i+1];
        else a[i+1] -= a[i];
      }
    }
    //assert(a == cp);
  }
}