#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

vector<int> a;
int n;

bool check(int i) {
	if (i < 0 || i >= n - 1) return true;
	if (i % 2) return (a[i] > a[i + 1]);
	return (a[i] < a[i + 1]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	a.resize(n);
	forn(i, 0, n) cin >> a[i];
	set<int> pos, to_check;
	forn(i, 0, n - 1)
		if (!check(i)) {
			pos.insert(i);
			pos.insert(i + 1);
			to_check.insert(i);
		}
	if (pos.size() >= 10) {
		cout << "0\n";
		return 0;
	}
	int s = pos.size();
	vector<int> posv(s);
	int i = 0;
	for (int t : pos) {
		posv[i] = t;
		++i;
	}
	set<pair<int, int>> ans;
	forn(i, 0, s) forn(j, 0, n) {
		if (posv[i] == j) continue;
		swap(a[posv[i]], a[j]);
		bool ok = true;
		for (int p : to_check) ok &= check(p);
		ok &= check(posv[i] - 1);
		ok &= check(posv[i]);
		ok &= check(j - 1);
		ok &= check(j);
		if (ok) {
			if (posv[i] < j) ans.insert({posv[i], j});
			else ans.insert({j, posv[i]});
		}
		swap(a[posv[i]], a[j]);
	}
	cout << ans.size() << '\n';
	return 0;
}