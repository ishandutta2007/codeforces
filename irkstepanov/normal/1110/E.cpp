#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
	}

	if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
		cout << "No\n";
		return 0;
	}

	map<int, int> x, y;
	for (int i = 1; i < n; ++i) {
		++x[a[i] - a[i - 1]];
		++y[b[i] - b[i - 1]];
	}

	for (auto it : x) {
		if (y[it.first] != it.second) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";

}