#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int a[100005], inv[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		inv[a[i]] = i;
	}

	cin >> m;
	ll cf=0, cb=0;
	for (int i=0; i<m; i++) {
		int x;
		cin >> x;
		x = inv[x];
		cf += x;
		cb += n-x+1;
	}

	cout << cf << ' ' << cb << '\n';
}