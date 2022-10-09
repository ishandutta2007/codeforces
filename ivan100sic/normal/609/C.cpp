// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}

	sort(a, a+n, greater<int>());
	ll z = accumulate(a, a+n, 0ll);

	ll s = 0;

	for (int i=0; i<n; i++) {
		s += abs(a[i] - (z/n + (i<z%n)));
	}

	cout << s/2 << '\n';
}