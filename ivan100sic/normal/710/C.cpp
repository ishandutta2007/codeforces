#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, e=0, o=-1, x;
	cin >> n;
	x = (n+1) / 2;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (abs(i-x) + abs(j-x) < x) {
				cout << (o += 2) << ' ';
			} else {
				cout << (e += 2) << ' ';
			}
		}
		cout << '\n';
	}
}