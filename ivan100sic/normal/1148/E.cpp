#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
pair<int, int> a[300005];
int b[300005];
basic_string<tuple<int, int, int>> sol;

void no() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i].first;
		a[i].second = i+1;
	}
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	sort(a, a+n);
	sort(b, b+n);

	int j = 1;
	for (int i=0; i<n; i++) {
		if (a[i].first > b[i]) {
			no();
		}

		while (a[i].first < b[i]) {
			if (j <= i)
				j = i+1;

			while (j < n && a[j].first <= b[j]) {
				j++;
			}
			if (j >= n)
				no();
			int delta = min(a[j].first - b[j], b[i] - a[i].first);
			sol += {a[i].second, a[j].second, delta};
			a[i].first += delta;
			a[j].first -= delta;
		}
	}

	cout << "YES\n" << sol.size() << '\n';
	for (auto [x, y, z]: sol)
		cout << x << ' ' << y << ' ' << z << '\n';
}