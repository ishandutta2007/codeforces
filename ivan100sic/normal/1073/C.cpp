#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef complex<int> ci;

int n;
ci a[200005], z[200005], cilj;

// sigurno je ok na parnost
bool moze(ci nova, int duzina) {
	int preko = abs(nova.real()) + abs(nova.imag()) - duzina;
	return preko <= 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	string s;
	cin >> s;
	for (int i=1; i<=n; i++) {
		char x = s[i-1];
		if (x == 'R')
			a[i] = {1, 0};
		else if (x == 'L')
			a[i] = {-1, 0};
		else if (x == 'U')
			a[i] = {0, 1};
		else if (x == 'D')
			a[i] = {0, -1};
		z[i] = z[i-1] + a[i];
	}

	{
		int x, y;
		cin >> x >> y;
		cilj = {x, y};

		int preko = abs(x) + abs(y) - n;
		if (preko > 0 || preko % 2) {
			cout << "-1\n";
			return 0;
		}

		if (cilj == z[n]) {
			cout << "0\n";
			return 0;
		}
	}

	int r = 0, sol = 12312323;
	for (int i=1; i<=n; i++) {
		if (r < i)
			r = i;
		while (1) {
			if (r > n)
				break;
			/* pre + X + posle = cilj */
			/* X = cilj - posle - pre */
			ci nova = cilj - (z[n] - z[r]) - z[i-1];
			if (moze(nova, r-i+1)) {
				break;
			} else {
				r++;
			}
		}
		if (r <= n)
			sol = min(sol, r-i+1);
	}
	if (sol == 12312323)
		sol = -1;
	cout << sol << '\n';
}