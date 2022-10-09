#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int pw(int x, int y, int p) {
	if (y == 0)
		return 1;

	int z = pw(x, y >> 1, p);
	z = z * 1ll * z % p;
	if (y & 1)
		z = z * 1ll * x % p;
	return z;
}

int pw(int x, string s, int p) {
	int z = 1;
	for (char c : s) {
		z = pw(z, 10, p);
		for (int i=0; i<c-'0'; i++)
			z = z * 1ll * x % p;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string b, n;
	int c;
	cin >> b >> n >> c;

	string nm1 = n;
	int x = nm1.size() - 1;
	nm1[x]--;
	while (nm1[x] == '0' - 1) {
		nm1[x] = '9';
		x--;
		nm1[x]--;
	}

	int bmodc = 0;
	for (char x : b) {
		bmodc = (10ll * bmodc + x - 48) % c;
	}

	int bn1 = pw(bmodc, nm1, c);
	int bn = bn1 * 1ll * bmodc % c;

	int raz = (bn - bn1 + c) % c;
	if (raz == 0)
		raz = c;
	cout << raz << '\n';
}