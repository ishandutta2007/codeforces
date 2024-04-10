// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void mx(ll& x, ll y) {
	x = max(x, y);
}

typedef ll state[3][2];

void df(state& s) {
	memset(s, 192, sizeof s);
}

int n;
int a[200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	if (n == 1) {
		cout << a[0] << '\n';
		return 0;
	}

	state ol; df(ol);
	ol[0][0] = 0;
	for (int i=0; i<n; i++) {
		state nu; df(nu);

		for (int j=0; j<3; j++) {
			for (int k=0; k<2; k++) {
				for (int u=0; u<2; u++) {
					// Ovo sam naboo
					mx(nu[(j+u) % 3][k|(u!=i%2)], ol[j][k] + (1-2*u)*a[i]);
				}
			}
		}

		memcpy(ol, nu, sizeof nu);
	}

	cout << ol[(2*n+1)%3][1] << '\n';
}