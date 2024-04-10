// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[100005], b[100005];
int n, m, k;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<m; i++) cin >> b[i];
	sort(a, a+n, greater<int>());
	sort(b, b+m, greater<int>());

	for (int i=0; i<max(n, m); i++) {
		if (a[i] > b[i]) return cout << "YES\n", 0;
	}
	cout << "NO\n";
}