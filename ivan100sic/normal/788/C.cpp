#include <bits/stdc++.h>
using namespace std;

int n, k;
int c[1005];
int d[2005];

int main() {
	// malo da ubrzamo ulaz/izlaz, ipak se ucitava 10^6 brojeva
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	while (k--) {
		int x;
		cin >> x;
		c[x] = 1;
	}

	fill(d, d+2001, -1);
	queue<int> q;

	for (int i=0; i<=1000; i++) {
		if (c[i] && i >= n) {
			d[i-n] = 1;
			q.push(i-n);
		}
	}

	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int i=0; i<=1000; i++) {
			int y = x+i-n;
			if (c[i] > 0 && y >= 0 && y <= 2000 && d[y] == -1) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}

	cout << d[0];	
}