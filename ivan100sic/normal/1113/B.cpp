#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[105], z, sol;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
		z += x;
	}

	for (int i=1; i<=100; i++) {
		if (!c[i])
			continue;
		for (int j=1; j<=100; j++) {
			if (!c[j])
				continue;
			if (i == j)
				continue;
			for (int x=1; x<=i; x++) {
				if (i % x == 0) {
					sol = max(sol, i+j-i/x-j*x);
				}
			}
		}
	}

	cout << z - sol << '\n';
}