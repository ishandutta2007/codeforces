#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
int first[nax], last[nax], a[nax];
int reach[nax];

int main() {
  fill_n(first, nax, 1e9);
  fill_n(last, nax,-1e9);

  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    first[a[i]] = min(first[a[i]], i);
    last[a[i]] = max(last[a[i]], i);
    reach[i] = i;
  }

  for (int v = 0; v < nax; v++) {
    if (last[v] == -1e9) continue;
    reach[first[v]] = max(reach[first[v]], last[v]);
  }

  int ans = 0, r = 0;
  map<int,int> count;
  for (int i = 0; i <= n; i++) {
    //cout << i << ' ' << reach[i] << endl;
    if (i >= r) {
      int ma = 0, sum = 0;
      for (auto p : count) {
	ma = max(ma, p.second);
	sum += p.second;
      }
      ans += sum-ma;
      count.clear();
    }
    if (i == n) break;
    count[a[i]]++;
    r = max(r, reach[i]+1);
  }
  cout << ans << endl;
}