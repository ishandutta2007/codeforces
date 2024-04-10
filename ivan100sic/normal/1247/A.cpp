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

	char x, y;
	cin >> x >> y;

	for (int a=1; a<=999; a++) {
		if (to_string(a)[0] == x && to_string(a+1)[0] == y) {
			cout << a << ' ' << a+1 << '\n';
			return 0;
		}
	}

	cout << "-1\n";
}