// Retired?
#include <bits/stdc++.h>
using namespace std;

// The problem statement sucks

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll n, b;
	ll a[2005];
	cin >> n >> b;
	for (int i=0; i<n; i++)
		cin >> a[i];

	ll sol = b;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			sol = max(sol, a[j] * (b / a[i]) + b % a[i]);
		}
	}

	cout << sol << '\n';
}