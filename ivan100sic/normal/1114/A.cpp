#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void no(string s = "NO\n") {
	cout << s;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;

	if (a < x || a+b < x+y || a+b+c < x+y+z) no();
	no("YES\n"); // xd
}