#include <bits/stdc++.h>
using namespace std;

int n;
int a[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}

	int last = n+1, sol = 0;
	for (int i=n; i>=1; i--) {
		if (i < last) {
			sol++;
		}
		last = min(last, i - a[i]);
	}
	cout << sol;
}