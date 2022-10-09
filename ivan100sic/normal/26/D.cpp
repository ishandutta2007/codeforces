#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cout << fixed << setprecision(20);

	int n, m, k;
	cin >> n >> m >> k;

	ld pn = 1, pm = 1;
	for (int i=1; i<=k+1; i++) {
		pn *= n+i;
		pm *= m-i+1;
	}

	cout << max(ld(0), (pn-pm)/pn) << '\n';
}