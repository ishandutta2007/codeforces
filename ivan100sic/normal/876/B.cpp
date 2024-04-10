#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<int> e[100005];
int n, k, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		e[x % m] += x;
	}

	for (int r=0; r<m; r++) {
		if ((int)e[r].size() >= k) {
			cout << "Yes\n";
			for (int i=0; i<k; i++)
				cout << e[r][i] << ' ';
			cout << '\n';
			return 0;
		}
	}

	cout << "No\n";
}