// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ld a, b, c;
	cin >> a >> b >> c;

	ld d = sqrt(b*b - 4*a*c);
	ld x = (-b+d) / (2*a);
	ld y = (-b-d) / (2*a);
	if (x < y)
		swap(x, y);
	cout << setprecision(20) << fixed;
	cout << x << '\n';
	cout << y << '\n';
}