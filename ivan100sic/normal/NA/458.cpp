#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string a[100005];
set<int> b;
pair<int, int> c[2000005];

void mark(int l, int r, int i) {
	while (1) {
		auto it = b.lower_bound(l);
		if (it == b.end() || *it > r)
			break;
		c[*it] = {i, *it-l};
		b.erase(it);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, h = 0;
	cin >> n;

	for (int i=1; i<=2000000; i++)
		b.insert(i);

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		int t;
		cin >> t;
		while (t--) {
			int x;
			cin >> x;
			int r = x + a[i].size() - 1;
			mark(x, r, i);
			h = max(h, r);
		}
	}

	for (int i=1; i<=h; i++) {
		if (c[i].first == 0)
			cout << 'a';
		else
			cout << a[c[i].first][c[i].second];
	}
	cout << '\n';
}