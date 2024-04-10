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

	int x, y, a=0, b=0, c=0;
	cin >> x >> y;
	for (int i=1; i<=6; i++) {
		int u = abs(i-x);
		int v = abs(i-y);
		if (u<v)
			a++;
		else if (u>v)
			b++;
		else
			c++;
	}
	cout << a << ' ' << c << ' ' << b << '\n';
}