// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

string s(int x) {
	return !x ? "Tidak" : "Ya";
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int znak = (a+b) % 2;
		int veliko = a || d;
		int malo = b || c;

		cout << s(znak && veliko) << ' ' << s(znak && malo) << ' ' << s(!znak && malo) << ' ' << s(!znak && veliko) << '\n';
	}
}