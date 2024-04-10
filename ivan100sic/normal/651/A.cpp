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

	int a, b, t = 0;
	cin >> a >> b;
	while (1) {
		if (a == 1 && b == 1)
			break;
		if (a == 0 || b == 0)
			break;
		if (a < b) {
			a += 1;
			b -= 2;
			t++;
		} else {
			a -= 2;
			b += 1;
			t++;
		}
	}
	cout << t << '\n';
}