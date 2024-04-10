#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll cena[2][300005];
ll zmija[2][300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> cena[0][i];
	for (int i=1; i<=n; i++)
		cin >> cena[1][i];

	for (int i=1; i<=n; i++) {
		if (i % 2) {
			zmija[0][i] = zmija[0][i-1] + cena[0][i] * (2*i-2);
			zmija[1][i] = zmija[0][i] + cena[1][i] * (2*i-1);			
		} else {
			zmija[1][i] = zmija[1][i-1] + cena[1][i] * (2*i-2);
			zmija[0][i] = zmija[1][i] + cena[0][i] * (2*i-1);
		}
	}

	ll zmija1 = 0, zmija2 = 0, zbir = 0, sol = zmija[n%2][n];

	for (int i=n; i>=1; i--) {
		zmija1 += - zbir + (2*i-2)*cena[1][i] + (2*n-1)*cena[0][i];
		zmija2 += - zbir + (2*i-2)*cena[0][i] + (2*n-1)*cena[1][i];
		
		zbir += cena[0][i] + cena[1][i];

		if (i % 2 == 0) {
			sol = max(sol, zmija1 + zmija[1][i-1]);
		} else {
			sol = max(sol, zmija2 + zmija[0][i-1]);
		}
	}

	cout << sol;
}