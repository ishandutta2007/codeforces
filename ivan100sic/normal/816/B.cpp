#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k, q;
int z[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> q;
	for (int i=0; i<n; i++) {
		int l, r;
		cin >> l >> r;
		z[l]++;
		z[r+1]--;
	}
	for (int i=1; i<=200000; i++)
		z[i] += z[i-1];
	for (int i=1; i<=200000; i++)
		z[i] = z[i] >= k;
	for (int i=1; i<=200000; i++)
		z[i] += z[i-1];
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << z[r] - z[l-1] << '\n';
	}
}