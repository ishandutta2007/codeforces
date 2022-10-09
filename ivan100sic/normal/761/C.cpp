#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int dist[55][4];

int n, m;

int d(int x) {
	return min(x, m-x);
}

int tip(char x) {
	if (isdigit(x)) {
		return 1;
	}
	if (isalpha(x)) {
		return 2;
	}
	return 3;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	memset(dist, 1, sizeof(dist));

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> s;
		for (int j=0; j<m; j++) {
			int t = tip(s[j]);
			dist[i][t] = min(dist[i][t], d(j));
		}
	}

	int sol = 1e9;

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (j == i) {
				continue;
			}
			for (int k=1; k<=n; k++) {
				if (k == i) {
					continue;
				}
				if (k == j) {
					continue;
				}

				sol = min(sol, dist[i][1] + dist[j][2] + dist[k][3]);
			}
		}
	}

	cout << sol;
}