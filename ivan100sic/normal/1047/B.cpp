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

	int n, b=0;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		b = max(b, x+y);
	}
	cout << b << '\n';
}