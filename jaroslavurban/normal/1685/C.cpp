#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n; n *= 2;
	string s; cin >> s;
	vector<int> a(n + 1);
	for (int i = 0; i < n; ++i) {
		a[i + 1] = a[i] + 2 * (s[i] == '(') - 1;
//		cerr << a[i + 1] << ' ';
	}
//	cerr << endl;
	int neg = 0;
	while (neg <= n && a[neg] >= 0) ++neg;
	if (neg == n + 1) { cout << "0\n"; return; }
	pair<int, int> mx = {0, 0}, smx = {0, 0}, lmx = {0, 0};
	for (int i = 0; i < neg; ++i) mx = max(mx, {a[i], i});
	for (int i = neg; i <= n; ++i) smx = max(smx, {a[i], i});
	int lneg = n;
	while (lneg >= 0 && a[lneg] >= 0) --lneg;
//	cerr << lneg << endl;
	for (int i = n; i > lneg; --i) lmx = max(lmx, {a[i], i});
	if (smx.first - lmx.first <= mx.first) {
		cout << "1\n";
		cout << mx.second + 1 << ' ' << lmx.second << '\n';
		return;
	}
	cout << "2\n";
	cout << mx.second + 1 << ' ' << smx.second << '\n';
	assert(smx.second + 1 <= n);
	cout << smx.second + 1 << ' ' << n << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}