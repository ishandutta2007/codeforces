// nice problem bro
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

const int W = 36;

int n;
int a[500005];
char g[500005][W];
int v[W];
map<ll, queue<int>> w;
basic_string<int> e[500005];
ll sol;

int main() {
	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n; i++) {
		for (int j=0; j<W; j++) {
			g[i][j] = uniform_int_distribution(0, 2)(eng);
		}
	}

	int h = 0;

	w[0].push(0);
	for (int i=0; i<n; i++) {
		// azuriraj tabelicu
		int x = a[i];
		if (e[x].size() == 4) {
			e[x][0] = i;
			rotate(begin(e[x]), begin(e[x]) + 1, end(e[x]));
			h = max(h, e[x][0] + 1);
		} else {
			e[x] += i;
			if (e[x].size() == 4) {
				h = max(h, e[x][0] + 1);
			}
		}

		ll z = 0;
		for (int j=0; j<W; j++) {
			v[j] = (v[j] + g[x][j]) % 3;
			z = 3*z + v[j];
		}

		auto& q = w[z];
		while (q.size() && q.front() < h) {
			q.pop();
		}

		sol += q.size();
		q.push(i+1);
	}

	cout << sol << '\n';
}