#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int w[200005], b[200005], c[200005];
int h[200005], W;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> w[i] >> h[i];
		W += w[i];
		b[i] = max(b[i-1], h[i]);
	}
	for (int i=n; i>=1; i--) {
		c[i] = max(c[i+1], h[i]);
	}
	for (int i=1; i<=n; i++) {
		cout << (W - w[i]) * max(b[i-1], c[i+1]) << ' ';
	}
	cout << '\n';
}