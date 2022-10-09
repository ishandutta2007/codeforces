#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int k, n;
int a[100005], c[100005], zc;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> k >> n;
	zc = k;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		c[x]++;
		if (c[x] == 1) {
			zc--;
			if (zc == 0) {
				zc = 0;
				for (int j=1; j<=k; j++) {
					c[j]--;
					if (c[j] == 0)
						zc++;
				}
				cout << '1';
			} else {
				cout << '0';
			}
		} else {
			cout << '0';
		}
	}
	cout << '\n';
}