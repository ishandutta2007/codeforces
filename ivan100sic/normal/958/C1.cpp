#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, p;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int z=0, q=0, s=0;
	cin >> n >> p;
	for (int i=1; i<=n; i++)
		cin >> a[i], z += a[i] % p;
	for (int i=1; i<n; i++)
		q += a[i] % p, s = max(s, q%p + (z-q)%p);
	cout << s << '\n';
}