#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int sd(int x) {
	int z = 0;
	while (x) {
		z += x % 10;
		x /= 10;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a;
	cin >> a;
	while (sd(a) % 4)
		a++;
	cout << a << '\n';
}