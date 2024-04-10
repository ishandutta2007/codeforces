#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5+10;
ll a[nax], b[nax], d[nax];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<ll,int>> add;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> d[i];
    add.emplace_back(a[i], i);
  }
  a[n] = 2e18;
  b[n] = 2e18;
  d[n] = 2e18;
  add.emplace_back(a[n], n);
  sort(add.begin(), add.end());

  set<pair<ll,int>> mind;
  ll last = 0, ans = 0, finish = 0;
  for (auto p : add) {
    int i = p.second;
    while (mind.size() && finish < a[i]) {
      ll dd;
      int j;
      tie(dd,j) = *mind.begin();
      if (b[j] < finish+d[j]) {
	mind.erase(mind.begin());
	continue;
      }
      ll end = min(a[i]+d[j]-1, b[j]);
      if (end >= finish+d[j]) {
	ll k = (end-finish)/d[j];
	finish += k*d[j];
	ans += k;
      }
    }

    if (a[i]+d[i] < finish) {
      finish = a[i]+d[i];
    }
    finish = max(finish, a[i]);
    mind.insert({d[i],i});
    last = a[i];
  }
  cout << ans << endl;
}