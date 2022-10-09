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

	int n, m;
	cin >> n >> m;
	if (n == m || n == m+1) {
		for (int i=0; i<n+m; i++)
			cout << (i&1);
		cout << '\n';
	} else if (n > m-1) {
		cout << "-1\n";
	} else if (m <= 2*n) {
		// stampaj 110 dok ne svedes na n=m
		while (n != m) {
			cout << "110";
			n -= 1;
			m -= 2;
		}

		for (int i=0; i<n; i++)
			cout << "10";
		cout << '\n';
	} else if (m <= 2*n+2) {
		for (int i=0; i<n+m; i++)
			cout << !!((i+1)%3);
		cout << '\n';
	} else {
		cout << "-1\n";
	}
}