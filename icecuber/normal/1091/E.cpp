#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

ll d[1000000];
ll prefix[1000000];

int main() {
  ios::sync_with_stdio(0);
  ll n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> d[i];
    d[i] *= -1;
  }
  sort(d, d+n);
  for (int i = 1; i <= n; i++)
    prefix[i] = -d[i-1]+prefix[i-1];

  ll low = 0, high = 1e9;
  for (ll k = 1; k <= n; k++) {
    ll ik = lower_bound(d, d+n, -k)-d;
    ik = max(ik, k-1);
    ll sum2 = 1LL*k*(ik-(k-1)) + prefix[n]-prefix[ik];
    sum2 = 1LL*k*(k-1) + sum2 - prefix[k];
    if (sum2 < 0) high = -1;

    high = min(high, sum2+(-d[k-1]));
    low = max(low, min((-d[k]),k)-sum2);
  }
  vector<int> ans;
  //cout << prefix[n] << endl;
  //cout << low << ' ' << high << endl;
  for (int i = low+(low%2 ^ prefix[n]%2); i <= high; i += 2)
    ans.push_back(i);
  if (!ans.size()) cout << -1 << endl;
  else {
    for (int i : ans) cout << i << ' ';
    cout << endl;
  }
}