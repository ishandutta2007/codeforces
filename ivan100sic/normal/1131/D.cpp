#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
string s[1005];
int kompr[1005], kompc[1005], k;
bool g[2005][2005];
int indeg[2005], d[2005], indeg_copy[2005];

void dfsc(int x);

void dfsr(int x) {
	kompr[x] = k;
	for (int y=0; y<m; y++) {
		if (s[x][y] == '=' && kompc[y] == 0) {
			dfsc(y);
		}
	}
}

void dfsc(int y) {
	kompc[y] = k;
	for (int x=0; x<n; x++) {
		if (s[x][y] == '=' && kompr[x] == 0) {
			dfsr(x);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];

	for (int i=0; i<n; i++) {
		if (!kompr[i]) {
			k++;
			dfsr(i);
		}
	}

	for (int j=0; j<m; j++) {
		if (!kompc[j]) {
			k++;
			dfsc(j);
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (s[i][j] == '<') {
				int x = kompr[i];
				int y = kompc[j];
				indeg[y] += 1 - g[x][y];
				g[x][y] = 1;
			} else if (s[i][j] == '>') {
				int x = kompr[i];
				int y = kompc[j];
				indeg[x] += 1 - g[y][x];
				g[y][x] = 1;
			}
		}
	}

	copy(indeg, indeg+2005, indeg_copy);

	queue<int> q;
	for (int i=1; i<=k; i++)
		if (indeg[i] == 0) {
			q.push(i);
			d[i] = 1;
		}

	while (q.size()) {
		int x = q.front(); q.pop();
		for (int y=1; y<=k; y++) {
			if (g[x][y]) {
				d[y] = max(d[x]+1, d[y]);
				indeg[y]--;
				if (indeg[y] == 0)
					q.push(y);
			}
		}
	}

	if (accumulate(indeg+1, indeg+k+1, 0ll)) {
		cout << "No\n";
		return 0;
	}

	cout << "Yes\n";
	for (int i=0; i<n; i++)
		cout << d[kompr[i]] << " \n"[i == n-1];
	for (int i=0; i<m; i++)
		cout << d[kompc[i]] << " \n"[i == m-1];
}