#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
vector<int> e[50005], l[50005];

int c[50005];

void mravmika() {
	for (int i=1; i<=n; i++) {
		int c1=0, c2=0;
		for (int j : e[i]) {
			if (c[j] == 1)
				c1++;
			else if (c[j] == 2)
				c2++;
		}
		c[i] = c1 < c2 ? 1 : 2;
	}
}

int t[1000055], T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		e[y].push_back(x);
	}

	for (int i=1; i<=n; i++) {
		int d;
		cin >> d;
		l[i].resize(d);
		for (int& x : l[i])
			cin >> x;
		T = max(*max_element(l[i].begin(), l[i].end()), T);
	}

	mravmika();

	while (1) {
		for (int i=1; i<=T; i+=8) {
			int r = rand() & 255;
			for (int j=0; j<8; j++)
				t[i+j] = ((r >> j) & 1) + 1;
		}

		// proveri da li su liste ok
		bool okk = true;

		for (int i=1; i<=n; i++) {
			bool ok = false;
			for (int boja : l[i]) {
				if (t[boja] == c[i]) {
					ok = true;
					break;
				}
			}
			if (!ok) {
				okk = false;
				break;
			}
		}

		if (okk) {
			for (int i=1; i<=n; i++)
				for (int boja : l[i])
					if (t[boja] == c[i]) {
						cout << boja << ' ';
						break;
					}
			cout << '\n';

			for (int i=1; i<=T; i++)
				cout << t[i] << ' ';

			return 0;
		}
	}
}