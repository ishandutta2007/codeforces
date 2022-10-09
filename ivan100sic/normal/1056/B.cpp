#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
ll a[1005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++)
		a[i*i % m] += n / m;
	for (int i=1; i<=n%m; i++)
		a[i*i % m] += 1;

	ll z = 0;

	for (int i=0; i<m; i++)
		for (int j=0; j<m; j++)
			if ((i+j) % m == 0)
				z += a[i] * a[j];

	cout << z << '\n';
}