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

	int m[6], w[6], hs, hu;

	for (int i=1; i<=5; i++)
		cin >> m[i];
	for (int i=1; i<=5; i++)
		cin >> w[i];
	cin >> hs >> hu;

	int s = 0;
	for (int i=1; i<=5; i++) {
		int x = 500 * i;
		s += max(x*3/10, x - x*m[i] / 250 - 50 * w[i]);
	}
	s += 100*hs - 50*hu;
	cout << s << '\n';
}