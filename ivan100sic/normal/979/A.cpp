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

	ll n, x;
	cin >> n;
	n++;

	if (n == 1)
		x = 0;
	else if (n % 2 == 0)
		x = n / 2;
	else
		x = n;

	cout << x << '\n';
}