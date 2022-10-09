#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, n;
	cin >> a >> b >> c >> n;

	int x = a-c;
	int y = b-c;
	int z = n-a-b+c;

	if (x < 0 || y < 0 || z < 1)
		return cout << -1, 0;

	cout << z << '\n';
}