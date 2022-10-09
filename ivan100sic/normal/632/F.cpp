#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[2500][2500];
basic_string<pair<int, int>> b, pending;
int n;

void no() {
	cout << "NOT MAGIC\n";
	exit(0);
}

bool cmp(pair<int, int> u, pair<int, int> v) {
	return a[u.first][u.second] < a[v.first][v.second];
}

bitset<2500> e[2500];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			cin >> a[i][j];

	for (int i=0; i<n; i++) {
		if (a[i][i] != 0)
			no();
		for (int j=0; j<n; j++)
			if (a[i][j] != a[j][i])
				no();
	}

	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			b += {i, j};
		}
	}
	sort(b.begin(), b.end(), cmp);
	pair<int, int> last = {0, 0};
	for (auto p : b) {
		if (cmp(last, p)) {
			for (auto q : pending) {
				e[q.first][q.second] = 1;
				e[q.second][q.first] = 1;
			}
			pending = {};
		}
		// cerr << "testing " << p.first << ' ' << p.second << '\n';
		if ((e[p.first] & e[p.second]).any())
			no();
		pending += p;
		last = p;
	}
	cout << "MAGIC\n";
}