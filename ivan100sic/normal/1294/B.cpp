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

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> a = {{0, 0}};
		for (int i=0; i<n; i++) {
			int x, y;
			cin >> x >> y;
			a.emplace_back(x, y);
		}
		sort(a.begin(), a.end());
		string s;
		int ok = 1;
		for (int i=0; i<n; i++) {
			if (a[i].first > a[i+1].first || a[i].second > a[i+1].second)
				ok = 0;
			else {
				s += string(a[i+1].first - a[i].first, 'R');
				s += string(a[i+1].second - a[i].second, 'U');
			}
		}
		if (ok)
			cout << "YES\n" << s << '\n';
		else
			cout << "NO\n";
	}
}