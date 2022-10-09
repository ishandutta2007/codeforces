#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	int g = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		g = gcd(g, a[i]);
	}

	for (int i=0; i<n; i++) {
		if (g == a[i]) {
			cout << a[i];
			return 0;
		}
	}
	cout << -1;
}