#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[6], b[6], n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		b[x]++;
	}

	for (int i=1; i<=5; i++)
		if ((a[i] + b[i]) % 2)
			return cout << "-1\n", 0;

	int sol = 0;
	for (int i=1; i<=5; i++)
		sol += abs(a[i] - b[i]);
	cout << sol / 4 << '\n';
}