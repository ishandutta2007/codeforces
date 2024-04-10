#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[200005];
ll z[200005], b[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);

	for (int i=0; i<n; i++)
		b[i+1] = b[i] + a[i];

	for (int i=0; i<m; i++)
		z[i+1] = z[i] + a[i];

	for (int i=m+1; i<=n; i++)
		z[i] = z[i-m] + b[i];


	for (int i=1; i<=n; i++)
		cout << z[i] << " \n"[i == n];
}