#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[105], b[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	for (int i=1; i<n; i++) {
		if (a[i] == a[i+1])
			b[i] = 0;
		else if (a[i] < a[i+1])
			b[i] = -1;
		else
			b[i] = 1;
	}

	cout << (is_sorted(b+1, b+n) ? "YES\n" : "NO\n");
}