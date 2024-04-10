#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[2000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	ll z = 0;
	int last = 2e9;
	for (int i=n-1; i>=0; i--) {
		int t = a[i] < last ? a[i] : last-1;
		if (t < 0)
			t = 0;
		last = t;
		z += t;
	}
	cout << z << '\n';
}