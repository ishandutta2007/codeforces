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
	int x, y = 0;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (x > y)
			y = x;
	}
	cout << (x^y) << '\n';
}