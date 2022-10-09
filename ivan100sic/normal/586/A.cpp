#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	int z = 0, t = 0;
	cin >> n;

	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		if (x == 1) {
			if (t == 0) {
				z++;
				t = 1;
			} else if (t == 1) {
				z++;
			} else if (t == 2) {
				z += 2;
				t = 1;
			}
		} else {
			if (t == 0) {
				// nista
			} else if (t == 1) {
				t = 2;
			} else if (t == 2) {
				t = 0;
			}
		}
	}

	cout << z << '\n';
}