#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	if (n == 1) {
		if (a[n] == 0) {
			cout << "UP\n";
		} else if (a[n] == 15) {
			cout << "DOWN\n";
		} else {
			cout << "-1\n";
		}
	} else {
		if (a[n] == 0) {
			cout << "UP\n";
		} else if (a[n] == 15) {
			cout << "DOWN\n";
		} else if (a[n] > a[n-1]) {
			cout << "UP\n";
		} else {
			cout << "DOWN\n";
		}
	}
}