#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[100005], s[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> c[i] >> s[i];
	}

	multiset<pair<int, int>> ms[2];

	for (int i=1; i<=n; i++) {
		ms[c[i]].insert({s[i], i});
	}

	while (ms[0].size() + ms[1].size() > 2) {
		auto p0 = *ms[0].begin();
		auto p1 = *ms[1].begin();

		bool crit;
		if (p0.first < p1.first)
			crit = true;
		else if (p0.first > p1.first)
			crit = false;
		else if (ms[0].size() > 1)
			crit = true;
		else
			crit = false;

		if (crit) {
			auto q1 = *ms[1].rbegin();
			ms[0].erase(p0);
			ms[1].erase(q1);

			cout << p0.second << ' ' << q1.second << ' ' << p0.first << '\n';
			q1.first -= p0.first;

			ms[1].insert(q1);
		} else {
			auto q0 = *ms[0].rbegin();
			ms[1].erase(p1);
			ms[0].erase(q0);

			cout << p1.second << ' ' << q0.second << ' ' << p1.first << '\n';
			q0.first -= p1.first;

			ms[0].insert(q0);
		}
	}

	cout << ms[0].begin()->second << ' ' << ms[1].begin()->second << ' ';
	cout << ms[0].begin()->first << '\n';
}