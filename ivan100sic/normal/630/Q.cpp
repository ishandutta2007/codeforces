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

	ld p = sqrt(ld(1) / 72);
	ld q = sqrt(ld(1) / 18);
	ld r = (sqrt(ld(5)) + 5) / 24;
	cout << setprecision(20) << fixed << a*a*a*p + b*b*b*q + c*c*c*r << '\n';
}