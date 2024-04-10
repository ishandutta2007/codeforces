#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int f[250005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m;
	cin >> n >> m;

	f[0] = 1;
	for (int i=1; i<=n; i++)
		f[i] = f[i-1] * 1ll * i % m;

	int sol = 0;
	for (int l=1; l<=n; l++)
		sol = (sol + f[l] * (n-l+1ll) % m * f[n-l+1] % m) % m;
	cout << sol << '\n';
}