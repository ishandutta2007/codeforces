#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int s[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, z = 0;
	cin >> a >> b;
	for (int i=a; i<=b; i++) {
		int x = i;
		while (x) {
			z += s[x % 10];
			x /= 10;
		}
	}
	cout << z << '\n';
}