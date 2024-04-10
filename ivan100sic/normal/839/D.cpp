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

const int MOD = 1'000'000'007;

int n;
int c[1000005];
int f[1000005];
bool mark[1000005];

int p2[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	p2[0] = 1;
	for (int i=1; i<=1000000; i++) {
		p2[i] = p2[i-1] * 2;
		if (p2[i] >= MOD) {
			p2[i] -= MOD;
		}
	}

	int sol = 0;

	for (int i=2; i<=1000000; i++) {
		// koliko ima deljivih sa i?
		int cc = 0;
		for (int j=i; j<=1000000; j+=i) {
			cc += c[j];
		}

		// nadji koeficijent
		int koef = i - f[i];
		for (int j=2*i; j<=1000000; j+=i) {
			f[j] += koef;
		}

		if (cc > 0) {
			//cerr << i << ' ' << cc << ' ' << koef << '\n';
			// dizi
			sol += cc * 1ll * p2[cc-1] % MOD * koef % MOD;
			if (sol >= MOD) {
				sol -= MOD;
			}
		}		
	}

	cout << sol;

}