// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, v;
int w[3005];
basic_string<int> e[3005], f[3005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> v;
	for (int i=0; i<n; i++) {
		int a, b;
		cin >> a >> b;
		e[a] += i;
		f[a+1] += i;
		w[i] += b;
	}

	int sol = 0;
	for (int i=1; i<=3001; i++) {
		int q = v;
		for (auto& g : {f, e}) {
			for (int j : g[i]) {
				int d = min(q, w[j]);
				w[j] -= d;
				q -= d;
				sol += d;
			}
		}
	}

	cout << sol << '\n';
}