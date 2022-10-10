#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int n, c;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=2; i<n; i++) {
		if ( (a[i] > a[i-1] && a[i] > a[i+1]) ||
		  (a[i] < a[i-1] && a[i] < a[i+1])) {
			c++;
		}

	}
	cout << c;
}