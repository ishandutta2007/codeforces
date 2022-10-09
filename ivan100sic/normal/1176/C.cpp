#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int inv[111];
int cnt[7], full;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	inv[4] = 1;
	inv[8] = 2;
	inv[15] = 3;
	inv[16] = 4;
	inv[23] = 5;
	inv[42] = 6;

	cin >> n;
	for (int i=0; i<n; i++) {
		int x;
		cin >> x;
		x = inv[x];
		if (x == 1) {
			cnt[1]++;
		} else {
			if (cnt[x-1] > 0) {
				cnt[x-1]--;
				cnt[x]++;
			}
		}
	}
	cout << n - 6*cnt[6] << '\n';
}