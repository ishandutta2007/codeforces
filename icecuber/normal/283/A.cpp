#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll d[300000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int l = 1;
  ll sum = 0;
  int q;
  cin >> q;
  cout << setprecision(20);
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int a, x;
      cin >> a >> x;
      sum += 1ll*a*x;
      d[a-1] += x;
    } else if (t == 2) {
      int k;
      cin >> k;
      sum += k;
      d[l-1] -= k;
      d[l++] = k;
    } else {
      sum -= d[l-1];
      d[l-2] += d[l-1];
      l--;
    }
    cout << sum*1./l << '\n';
  }
}