#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll k, n, s, p;
	cin >> k >> n >> s >> p;

	ll x = (n+s-1)/s;
	x *= k;
	ll y = (x+p-1)/p;
	cout << y;
}