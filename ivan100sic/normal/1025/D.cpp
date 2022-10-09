#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

bool levo[705][705], desno[705][705];
bool e[705][705];
int a[705], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<=n; i++)
		for (int j=1; j<=n; j++)
			e[i][j] = gcd(a[i], a[j]) > 1;

	bool ok = false;

	for (int l=n; l>=1; l--) {
		for (int r=l; r<=n; r++) {
			for (int x=l; x<=r; x++) {
				bool mozeee = (levo[l][x] || (l == x))
							&& (desno[x][r] || (x == r));

				levo[l][r+1] |= mozeee && e[x][r+1];
				desno[l-1][r] |= mozeee && e[l-1][x];

				if (l == 1 && r == n)
					ok |= mozeee;
			}
		}
	}

	cout << (ok ? "Yes" : "No");
}