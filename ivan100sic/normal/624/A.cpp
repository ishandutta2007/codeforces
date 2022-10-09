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

	cout.precision(20);
	cout << fixed;

	ld a, b, c, d;
	cin >> a >> b >> c >> d;
	cout << (b-a) / (c+d) << '\n';
}