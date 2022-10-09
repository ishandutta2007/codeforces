#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll b[200005], a[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n/2; i++)
		cin >> b[i];
	for (int i=1; i<=n/2; i++) {
		a[i] = max(a[i-1], i > 1 ? b[i] - a[n-i+2] : 0ll);
		a[n-i+1] = b[i] - a[i];
	}
	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';
	cout << '\n';
}