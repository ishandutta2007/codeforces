#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> a(n), b(n), taken(n + 1);
	for (int& v : a) cin >> v;
	for (int& v : b) cin >> v;
	bool pos = a.back() == b.back();
	int i = n - 2, j = n - 2;
	while (pos && j >= 0) {
		if (a[i] == b[j]) --i, --j;
		else {
			if (b[j] == b[j + 1]) ++taken[b[j]], --j;
			else {
				if (taken[a[i]]) --taken[a[i]], --i;
				else { pos = false; break; }
			}
		}
	}
	for (int k = 0; k <= i; ++k) if (!taken[a[k]]--) pos = false;
	cout << (pos ? "YES\n" : "NO\n");
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}