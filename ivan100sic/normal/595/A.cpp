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

	int n, m, s=0;
	cin >> n >> m;
	n *= m;
	while (n--) {
		int x, y;
		cin >> x >> y;
		s += x | y;
	}
	cout << s << '\n';
}