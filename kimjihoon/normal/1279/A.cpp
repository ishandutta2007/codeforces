#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tc; cin >> tc;
	for (int ti = 0; ti < tc; ti++) {
		int a, b, c; cin >> a >> b >> c;
		if (a > c) swap(a, c);
		if (b > c) swap(b, c);
		if (a + b < c - 1) cout << "No" << '\n';
		else cout << "Yes" << '\n';
	}
	return 0;
}