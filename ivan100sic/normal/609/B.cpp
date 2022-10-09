// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int c[11];
ll z;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	for (int i=1; i<=m; i++) {
		for (int j=i+1; j<=m; j++) {
			z += c[i] * c[j];
		}
	}

	cout << z << '\n';
}