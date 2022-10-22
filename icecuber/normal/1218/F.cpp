#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x[100000];
ll cost[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, str;
  cin >> n >> str;
  for (int i = 0; i < n; i++) cin >> x[i];
  ll A;
  cin >> A;
  for (int i = 0; i < n; i++) cin >> cost[i];

  priority_queue<ll> drink;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    drink.push(-cost[i]);
    while (str < x[i]) {
      if (drink.empty()) {
	cout << -1 << endl;
	return 0;
      }
      ans -= drink.top();
      str += A;
      drink.pop();
    }
  }
  cout << ans << endl;
}