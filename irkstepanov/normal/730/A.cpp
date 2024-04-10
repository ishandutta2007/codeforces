#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

int main()
{

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int r = 100; r; --r) {
		vector<int> d(n);
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] < r) {
				ok = false;
				break;
			}
			d[i] = a[i] - r;
			sum += d[i];
		}
		if (!ok) {
			continue;
		}
		vector<vector<int> > ans;
		if (sum & 1) {
			int maxx = -1;
			for (int i = 0; i < n; ++i) {
				if (d[i] > 0 && (maxx == -1 || d[maxx] < d[i])) {
					maxx = i;
				}
			}
			if (maxx == -1) {
				continue;
			}
			ans.pb({});
			ans.back().pb(maxx);
			--d[maxx];
			int maxx2 = -1;
			for (int i = 0; i < n; ++i) {
				if (d[i] > 0 && i != maxx && (maxx2 == -1 || d[maxx2] < d[i])) {
					maxx2 = i;
				}
			}
			if (maxx2 == -1) {
				continue;
			}
			ans.back().pb(maxx2);
			--d[maxx2];
			int maxx3 = -1;
			for (int i = 0; i < n; ++i) {
				if (d[i] > 0 && i != maxx && i != maxx2 && (maxx3 == -1 || d[maxx3] < d[i])) {
					maxx3 = i;
				}
			}
			if (maxx3 == -1) {
				continue;
			}
			ans.back().pb(maxx3);
			--d[maxx3];
			sum -= 3;
		}
		while (sum) {
			int maxx = -1;
			for (int i = 0; i < n; ++i) {
				if (d[i] > 0 && (maxx == -1 || d[maxx] < d[i])) {
					maxx = i;
				}
			}
			if (maxx == -1) {
				ok = false;
				break;
			}
			ans.pb({});
			ans.back().pb(maxx);
			--d[maxx];
			int maxx2 = -1;
			for (int i = 0; i < n; ++i) {
				if (d[i] > 0 && i != maxx && (maxx2 == -1 || d[maxx2] < d[i])) {
					maxx2 = i;
				}
			}
			if (maxx2 == -1) {
				ok = false;
				break;
			}
			ans.back().pb(maxx2);
			--d[maxx2];
			sum -= 2;
		}
		if (!ok) {
			continue;
		}
		cout << r << "\n";
		cout << sz(ans) << "\n";
		for (int j = 0; j < sz(ans); ++j) {
			vector<char> v(n, false);
			for (int x : ans[j]) {
				v[x] = true;
			}
			for (char c : v) {
				if (c) {
					cout << "1";
				} else {
					cout << "0";
				}
			}
			cout << "\n";
		}
		return 0;
	}

	cout << "0\n";
	cout << 100 * (n - 1) << "\n";
	for (int i = 0; i < n - 1; ++i) {
		for (int t = 0; t < 100; ++t) {
			for (int j = 0; j < i; ++j) {
				cout << "0";
			}
			cout << "11";
			for (int j = i + 2; j < n; ++j) {
				cout << "0";
			}
			cout << "\n";
		}
	}

}