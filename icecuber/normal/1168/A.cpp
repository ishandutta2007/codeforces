#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  int fail = -1, pass = m;
  while (pass-fail > 1) {
    int mid = pass+fail>>1;
    int ok = 1, v = 0;
    for (int i = 0; i < n; i++) {
      int x = (v-a[i]+m)%m;
      if (x <= mid) continue;
      if (a[i] < v) {ok = 0;break;}
      v = a[i];
    }
    if (ok) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}