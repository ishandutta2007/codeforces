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

	int n, z = 0;
	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		z += x;
	}
	int c = 0;
	for (int i=1; i<=5; i++) {
		if ((z+i) % (n+1) != 1)
			c++;
	}
	cout << c << '\n';
}