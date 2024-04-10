#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> a;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a += x;
	}
	a += a;
	int z = 0, y = 0;
	for (int x : a) {
		y = x ? y+1 : 0;
		z = max(z, y);
	}
	cout << z << '\n';
}