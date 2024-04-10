#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
	int d = 0, f;
	forn(i, 0, p.size()) {
		cout << p[i] << endl;
		string s;
		cin >> s;
		if (s == "yes") {
			++d;
			f = p[i];
		}
	}
	if (d >= 2) {
		cout << "composite" << endl;
	} else if (d == 0) {
		cout << "prime" << endl;
	} else {
		if (f * f > 100) {
			cout << "prime" << endl;
		} else {
			cout << f * f << endl;
			string s;
			cin >> s;
			if (s == "yes") cout << "composite" << endl;
			else cout << "prime" << endl;
		}
	}
	return 0;
}