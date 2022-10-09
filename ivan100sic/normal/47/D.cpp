// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
ll g[10], sol;
int v[10];

void rek(ll b, int k) {
	int ok = 1;
	for (int i=0; i<m; i++) {
		ll mask = (1ll << k) - 1;
		int diff = __builtin_popcountll((g[i] ^ b ^ mask) & mask) - v[i];
		if (diff > 0) return;
		if (diff < 0) ok = 0;
	}

	if (k == n) {
		sol += ok;
		return;
	}

	rek(b + (1ll << k), k+1);
	rek(b, k+1);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		string s;
		cin >> s;
		ll z = 0;
		for (char c : s) {
			z = 2*z + c - '0';
		}
		g[i] = z;
		cin >> v[i];
	}

	rek(0, 0);
	cout << sol << '\n';
}