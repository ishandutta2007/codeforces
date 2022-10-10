#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	int t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

int n;
int a[2005];
int b[2005];

void hackmenow() {
	int kec = 0;
	for (int i=1; i<=n; i++) {
		if (a[i] == 1) {
			kec = i;
		}
	}
	if (kec) {
		cout << n - count(a+1, a+n+1, 1);
		exit(0);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	hackmenow();

	int sol = 123123;

	for (int i=1; i<=n; i++) {
		int g = 0;
		for (int j=i; j<=n; j++) {
			g = gcd(g, a[j]);
			if (g == 1) {
				sol = min(sol, n-1 + j-i);
				break;
			}
		}
	}

	if (sol == 123123) {
		sol = -1;
	}

	cout << sol;




}