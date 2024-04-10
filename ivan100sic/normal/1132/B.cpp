#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[300005], z[300005];
int m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	for (int i=0; i<n; i++)
		z[i+1] = z[i] + a[i];
	cin >> m;
	for (int i=0; i<m; i++) {
		int q;
		cin >> q;
		cout << z[n] - a[n-q] << '\n';
	}
}