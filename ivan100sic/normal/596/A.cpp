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

	int n;
	cin >> n;
	int x1 = 123123, x2 = -123123;
	int y1 = 123123, y2 = -123123;
	while (n--) {
		int x, y;
		cin >> x >> y;
		x1 = min(x1, x);
		x2 = max(x2, x);
		y1 = min(y1, y);
		y2 = max(y2, y);
	}

	int a = (y2-y1)*(x2-x1);
	if (a == 0)
		a = -1;
	cout << a << '\n';
}