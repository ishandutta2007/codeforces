#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int& v : a) cin >> v;
	int b[2] = {-1, -1};
	bool pos = true;
	for (int i = 0; i < n; ++i) {
		if (b[a[i] & 1] > a[i]) pos = false;
		b[a[i] & 1] = max(b[a[i] & 1], a[i]);
	}
	if (pos) cout << "yes\n";
	else cout << "no\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}