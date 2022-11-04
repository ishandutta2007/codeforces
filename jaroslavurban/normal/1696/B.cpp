#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	bool nonzero = false;
	int swaps = 0;
	for (int a, i = 0; i < n; ++i) {
		cin >> a;
		nonzero |= a != 0;
		if ((swaps & 1) != (a != 0)) ++swaps;
	}
	if (!nonzero) cout << "0\n";
	else if (swaps <= 2) cout << "1\n";
	else cout << "2\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}