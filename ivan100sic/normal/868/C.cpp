#include <bits/stdc++.h>
using namespace std;

int c[16];
int n, k;

bool check(int a, int b) {
	return (a & b) == 0;
}

bool check(int a, int b, int c) {
	return (a & b) == 0 && (b & c) == 0 && (c & a) == 0;
}

bool check(int a, int b, int c, int d) {
	vector<int> x = {a, b, c, d}, v(4, 0);
	for (int y : x) {
		for (int i=0; i<4; i++) {
			if (y & (1<<i)) {
				v[i]++;
			}
		}
	}

	return *max_element(v.begin(), v.end()) <= 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		int m = 0;
		for (int j=1; j<=k; j++) {
			int x;
			cin >> x;
			m = 2*m + x;
		}
		c[m]++;
	}

	int h = (1<<k);

	if (c[0]) {
		cout << "YES";
		return 0;
	}

	for (int i=0; i<h; i++) {
		if (!c[i]) continue;
		c[i]--;
		for (int j=0; j<h; j++) {
			if (!c[j]) continue;
			c[j]--;
			
			if (check(i, j)) {
				cout << "YES";
				return 0;
			}

			c[j]++;
		}
		c[i]++;
	}

	for (int i=0; i<h; i++) {
		if (!c[i]) continue;
		c[i]--;
		for (int j=0; j<h; j++) {
			if (!c[j]) continue;
			c[j]--;
			for (int x=0; x<h; x++) {
				if (!c[x]) continue;
				c[x]--;
				
				if (check(i, j, x)) {
					cout << "YES";
					return 0;
				}


				c[x]++;
			}
			c[j]++;
		}
		c[i]++;
	}

	for (int i=0; i<h; i++) {
		if (!c[i]) continue;
		c[i]--;
		for (int j=0; j<h; j++) {
			if (!c[j]) continue;
			c[j]--;
			for (int x=0; x<h; x++) {
				if (!c[x]) continue;
				c[x]--;
				for (int y=0; y<h; y++) {
					if (!c[y]) continue;
					c[y]--;

					if (check(i, j, x, y)) {
						cout << "YES";
						return 0;
					}

					c[y]++;
				}
				c[x]++;
			}
			c[j]++;
		}
		c[i]++;
	}

	cout << "NO";
	return 0;




}