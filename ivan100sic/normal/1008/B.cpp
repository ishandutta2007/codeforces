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

	int n, l=0;
	cin >> n;
	int x, y;
	cin >> x >> y;
	n--;
	y = max(x, y);
	while (n--) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			swap(a, b);
		if (b <= y)
			y = b;
		else if (a <= y)
			y = a;
		else
			l = 1;
	}
	cout << (l ? "NO" : "YES");
}