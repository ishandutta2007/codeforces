#include <bits/stdc++.h>
using namespace std;

int n;
int q[300005];
int a[300005];
int empty;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> q[i];
	}

	empty = n;

	cout << "1\n";

	for (int i=1; i<=n; i++) {
		a[q[i]] = 1;
		while (a[empty]) {
			empty--;
		}
		cout << i - (n - empty - 1) << '\n';
	}


}