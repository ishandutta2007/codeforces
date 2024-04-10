#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int h[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> h[i];
	ll sol = 0;
	int x = 0;
	for (int i=1; i<=n; i++) {
		// popni se do vrha
		sol += h[i] - x;
		x = h[i];
		// jedi
		sol += 1;
		// skaci dalje
		if (i < n) {
			if (x > h[i+1]) {
				sol += x - h[i+1];
				x = h[i+1];
			}
			sol += 1;
		}
	}	
	cout << sol << '\n';
}