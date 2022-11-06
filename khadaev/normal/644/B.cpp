#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, b;
	cin >> n >> b;
	queue<pair<int, int>> q;
	vector<ll> ans(n);
	ll time = 0;
	forn(i, 0, n) {
		int t, d;
		cin >> t >> d;
		while (!q.empty() && time + q.front().fs <= t) {
			time += q.front().fs;
			ans[q.front().sn] = time;
			q.pop();
		}
		if (q.empty()) time = t;
		if (q.size() == b + 1) ans[i] = -1;
		else q.push({d, i});
	}
	while (!q.empty()) {
		time += q.front().fs;
		ans[q.front().sn] = time;
		q.pop();
	}
	for (ll i : ans) cout << i << ' ';
	return 0;
}