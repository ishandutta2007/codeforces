#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll p[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll mi = 0, ma = 0;
  for (int i = 1; i < n; i++) {
    ll q;
    cin >> q;
    p[i] = p[i-1]+q;
    mi = min(mi, p[i]);
    ma = max(ma, p[i]);
  }
  int ok = ma-mi == n-1;
  int add = 1-mi;
  set<int> has;
  for (int i = 0; i < n; i++)
    has.insert(p[i]+add);
  ok &= has.size() == n;
  if (ok) {
    for (int i = 0; i < n; i++)
      cout << p[i]+add << ' ';
    cout << endl;
  } else cout << -1 << endl;
}