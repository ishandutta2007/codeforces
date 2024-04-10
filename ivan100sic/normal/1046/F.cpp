#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[200005], f, x;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	cin >> x >> f;
	ll sol = 0;
	for (int i=0; i<n; i++) {
		sol += (a[i] - x + f + x - 1) / (f + x) * f;
	}
	cout << sol << '\n';
}