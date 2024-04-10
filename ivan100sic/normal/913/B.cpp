#include <bits/stdc++.h>
using namespace std;

int n;
int p[1005];
int c[1005]; // broj dece
int b[1005]; // broj leaf dece

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++) {
		cin >> p[i];
		c[p[i]]++;
	}

	for (int i=1; i<=n; i++) {
		if (c[i] == 0) {
			b[p[i]]++;
		}
	}

	for (int i=1; i<=n; i++) {
		if (c[i] > 0 && b[i] < 3) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";
}