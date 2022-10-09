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

	int b, k, z=0;
	cin >> b >> k;
	while (k--) {
		int x;
		cin >> x;
		z = (z * b + x) % 2;
	}

	cout << (z ? "odd\n" : "even\n");
}