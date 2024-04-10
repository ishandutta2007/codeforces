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

	int n, y = 0;
	cin >> n;
	for (int x : {1, 6, 28, 120, 496, 2016, 8128, 32640})
		if (n % x == 0)
			y = x;
	cout << y << '\n';
}