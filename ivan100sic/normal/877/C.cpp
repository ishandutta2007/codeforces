#include <bits/stdc++.h>
using namespace std;



int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	if (n % 2 == 0) {
		cout << n/2*3 << '\n';
		for (int i=2; i<=n; i+=2) {
			cout << i << ' ';
		}
		for (int i=1; i<=n; i+=2) {
			cout << i << ' ';
		}
		for (int i=2; i<=n; i+=2) {
			cout << i << ' ';
		}
	} else {
		cout << n/2*3+1 << '\n';
		for (int i=2; i<=n; i+=2) {
			cout << i << ' ';
		}
		for (int i=1; i<=n; i+=2) {
			cout << i << ' ';
		}
		for (int i=2; i<=n; i+=2) {
			cout << i << ' ';
		}
	}
}