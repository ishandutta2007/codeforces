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
	ll res = 0, pos = 0;
	ll sm = 0, cnt0 = 0, cnt1 = 0, cnt3 = 0, cntb = 0, cnte = 0;
	for (int i = 1; i + 1 < n; ++i) {
		cnt0 += !a[i];
		cnt1 += a[i] == 1;
		cnt3 += a[i] == 3;
		cntb += a[i] > 3 && (a[i] & 1);
		cnte += a[i] > 0 && !(a[i] & 1);
		res += (a[i] + 1) / 2;
	}
	if (n - 2 == 1) {
		if (a[1] & 1) cout << "-1\n";
		else cout << res << "\n";
		return;
	}
	if (cnte) cout << res << "\n";
	else if (cnt0 == n - 2) cout << res << "\n";
	else if (!cntb) {
		if (cnt1 + cnt3 <= 1 || cnt3 == 0) cout << "-1\n";
		else cout << res << "\n";
	} else {
		if (cntb + cnt1 + cnt3 <= 1) cout << res + 1 << "\n";
		else cout << res << "\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}