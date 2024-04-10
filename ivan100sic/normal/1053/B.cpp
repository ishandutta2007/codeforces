#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[300005];
int b[300005], zz;
int par[300005], nepar[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	par[0] = 1;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = __builtin_popcountll(a[i]);
		par[i] = par[i-1];
		nepar[i] = nepar[i-1];

		zz += b[i];

		if (zz % 2)
			nepar[i]++;
		else
			par[i]++;
	}

	ll sol = 0;

	int sve = 0;

	for (int i=1; i<=n; i++) {
		int sum = 0, hi = 0;
		sve += b[i];
		for (int j=i-1; j>=0; j--) {
			sum += b[j+1];
			hi = max(hi, b[j+1]);

			if (sum >= 120) {
				// cerr << "dodajem " << ((sve & 1) ? nepar[j-1] : par[j-1]) << '\n';
				sol += ((sve & 1) ? nepar[j] : par[j]);
				break;
			}

			if (hi + hi <= sum && !(sum & 1)) {
				sol++;
			}
		}
	}

	cout << sol << '\n';
}