#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k, t;
  cin >> n >> m >> k >> t;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.rbegin(), a.rend());

  vector<int> l(k), r(k), d(k);
  for (int i = 0; i < k; i++) {
    cin >> l[i] >> r[i] >> d[i];
    l[i]--;
  }

  int pass = 0, fail = n+1;
  while (fail-pass > 1) {
    int mid = pass+fail>>1;
    int thres = a[mid-1];
    vector<pair<int,int>> inv;
    for (int i = 0; i < k; i++) {
      if (thres < d[i]) {
	inv.emplace_back(l[i], r[i]);
      }
    }
    sort(inv.begin(), inv.end());
    int need = m+1;
    int reach = -1;
    for (auto it : inv) {
      int l, r;
      tie(l,r) = it;
      if (r > reach) {
	need += (r-max(reach, l))*2;
	reach = max(reach, r);
      }
    }
    if (need <= t) pass = mid;
    else fail = mid;
  }
  cout << pass << endl;
}