#include <bits/stdc++.h>
using namespace std;

int n;
int d[505][505];
int b[505];
long long sol[505];

vector<int> cvorovi;

int main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> d[i][j];
		}
	}
	for (int i=1; i<=n; i++) {
		cin >> b[i];
	}
	for (int i=1; i<=n; i++) {
		int k = b[n-i+1];

		for (int u : cvorovi) {
			for (int v : cvorovi) {
				d[u][k] = min(d[u][k], d[u][v] + d[v][k]);
			}
		}

		for (int u : cvorovi) {
			for (int v : cvorovi) {
				d[k][u] = min(d[k][u], d[k][v] + d[v][u]);
			}
		}

		for (int u : cvorovi) {
			for (int v : cvorovi) {
				d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
			}
		}

		cvorovi.push_back(k);

		for (int u : cvorovi) {
			for (int v : cvorovi) {
				sol[i] += d[u][v];
			}
		}
	}

	for (int i=n; i>=1; i--) {
		cout << sol[i] << ' ';
	}
}