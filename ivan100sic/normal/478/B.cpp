#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	ll sx = n / m + 1;
	ll x = n % m;
	ll sy = sx - 1;
	ll y = m - x;

	cout << x*sx*(sx-1)/2 + y*sy*(sy-1)/2;
	cout << ' ' << (n-m+1)*(n-m) / 2 << '\n';
}