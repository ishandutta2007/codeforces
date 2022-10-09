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

	ll a, b;
	cin >> a >> b;
	a = min(a, b);
	ll p = 1;
	for (ll i=2; i<=a; i++)
		p *= i;
	cout << p;
}