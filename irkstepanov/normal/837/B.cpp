#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	set<char> s;

	vector<vector<char> > a(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			s.insert(a[i][j]);
		}
	}

	if (sz(s) != 3) {
		cout << "NO\n";
		return 0;
	}

	if (n % 3 == 0) {
		bool ok = true;
		for (int start = 0; start < n; start += n / 3) {
			for (int i = 0; i < n / 3; ++i) {
				for (int j = 0; j < m; ++j) {
					if (a[start + i][j] != a[start][0]) {
						ok = false;
					}
				}
			}
		}
		if (ok) {
			cout << "YES\n";
			return 0;
		}
	}

	if (m % 3 == 0) {
		bool ok = true;
		for (int start = 0; start < m; start += m / 3) {
			for (int j = 0; j < m / 3; ++j) {
				for (int i = 0; i < n; ++i) {
					if (a[i][j + start] != a[0][start]) {
						ok = false;
					}
				}
			}
		}
		if (ok) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";

}