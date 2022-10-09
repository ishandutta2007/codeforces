#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[22], c[22];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	while (m--) {
		int x;
		cin >> x;
		c[x]++;
	}
	for (int i=0; i<n; i++)
		if (c[a[i]])
			cout << a[i] << ' ';
	cout << "\n";
}