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

bool leap(int n) {
	if (n % 400 == 0) return true;
	if (n % 100 == 0) return false;
	return (n % 4 == 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int day = 0;
	fore(i, 1, n) {
		day += 365;
		if (leap(n)) ++day;
		day %= 7;
	}
	int nday = day, nn = n;
	do {
		++nn;
		day += 365;
		if (leap(nn)) ++day;
		day %= 7;
	} while (nday != day || leap(nn) != leap(n));
	cout << nn << '\n';
	return 0;
}