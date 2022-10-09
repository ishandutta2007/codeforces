#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

bool ok(ll w, ll m) {
	if (!w) return 1;
	if (w % m == 0)
		return ok(w/m, m);
	if (((w % m) + m) % m == 1)
		return ok(w-1, m);
	if (((w % m) + m) % m == m - 1)
		return ok(w+1, m);
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);
	
	ll w, m;
	cin >> m >> w;
	
	cout << (ok(w, m) ? "YES\n" : "NO\n");
}