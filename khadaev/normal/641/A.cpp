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
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	forn(i, 0, n) cin >> a[i];
	vector<bool> used(n);
	int pos = 0;
	while (1) {
		if (used[pos]) {
			cout << "INFINITE\n";
			return 0;
		} else {
			used[pos] = 1;
			int d = a[pos];
			if (s[pos] == '<') d *= -1;
			pos += d;
			if (pos < 0 || pos >= n) {
				cout << "FINITE\n";
				return 0;
			}
		}
	}
	return 0;
}