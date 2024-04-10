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

	int n, l = 0;
	bool nula = false;
	ll z = 0;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (x == 0)
			nula = true, z++;
		else if (x < 0)
			z += -1-x, l++;
		else
			z += x-1;
	}

	if (l % 2 && !nula)
		z += 2;

	cout << z << '\n';
}