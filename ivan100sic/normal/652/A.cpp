// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int u, v;
	cin >> u >> v;
	v -= u;
	int a, b;
	cin >> a >> b;
	v -= 8*a;
	if (v <= 0)
		return cout << "0\n", 0;
	a -= b;
	a *= 12;
	if (a <= 0)
		cout << "-1\n";
	else
		cout << (v + a - 1) / a << '\n';
}