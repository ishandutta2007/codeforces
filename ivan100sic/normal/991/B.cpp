#include <bits/stdc++.h>
using namespace std;

int n;
int c[105];

bool ok() {
	int z = 2*c[2] + 3*c[3] + 4*c[4] + 5*c[5];
	return 2*z >= 9*n;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
	}

	int s = 0;
	while (!ok()) {
		for (int i=2; i<5; i++) {
			if (c[i] > 0) {
				s++;
				c[i]--;
				c[5]++;
				break;
			}
		}
	}

	cout << s;
}