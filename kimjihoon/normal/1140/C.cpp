#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
using namespace std;
typedef long long ll;

pair<ll, ll> p[300009];
priority_queue<ll, vector<ll>, greater<ll>> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> p[i].second >> p[i].first;
	sort(p, p + n); reverse(p, p + n);
	ll l = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		if (i < k) {
			l += p[i].second;
			q.push(p[i].second);
		}
		else if (q.top() < p[i].second) {
			l += p[i].second - q.top();
			q.pop(); q.push(p[i].second);
		}
		ans = max(ans, l * p[i].first);
	}
	cout << ans << '\n';
	return 0;
}