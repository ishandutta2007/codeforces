#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[1000005];
int c[1000005];
int d[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] <= m)
			c[a[i]]++;
	}
	for (int i=1; i<=m; i++)
		for (int j=i; j<=m; j+=i)
			d[j] += c[i];

	int x = max_element(d+1, d+m+1) - d;
	cout << x << ' ' << d[x] << '\n';
	for (int i=0; i<n; i++) {
		if (x % a[i] == 0)
			cout << i+1 << ' ';
	}
	cout << '\n';
}