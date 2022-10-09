#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;

void dodaj(int x, int y) {
	cout << x << ' ' << y << '\n';
	if (--n == 0)
		exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;

	if (n > k*(k-1ll)) {
		cout << "nO\n";
		return 0;
	}

	cout << "yES\n";

	int x=0;

	for (int i=1; i<=k; i++) {
		for (int j=i+1; j<=k; j++) {
			if (i == x) {
				dodaj(j, i);
				dodaj(i, j);
				x = i;
			} else {
				dodaj(i, j);
				dodaj(j, i);
				x = j;
			}
		}
	}
}