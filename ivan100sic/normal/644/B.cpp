#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, b;
	cin >> n >> b;
	basic_string<ll> ans(n, 0);
	auto t = ans;
	auto d = ans;
	ll server_time = 0;
	queue<int> q;
	for (int i=0; i<n; i++) {
		cin >> t[i] >> d[i];
		// fast forward to t[i]
		while (server_time <= t[i]) {
			if (q.size()) {
				int j = q.front();
				q.pop();
				ans[j] = server_time += d[j];
			} else {
				server_time = t[i];
				break;
			}
		}

		if (server_time < t[i])
			server_time = t[i];

		if ((int)q.size() < b) {
			q.push(i);
		} else {
			ans[i] = -1;
		}
	}

	while (q.size()) {
		int j = q.front();
		q.pop();
		ans[j] = server_time += d[j];
	}

	for (ll x : ans)
		cout << x << ' ';
	cout << '\n';
}