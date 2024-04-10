#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k;
string a, b;
ll w[500005], d[500005];

const ll BIG = 123123123123123ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> a >> b;
	a = string(" ") + a;
	b = string(" ") + b;
	w[0] = 1;
	for (int i=1; i<=n; i++) {
		if (a[i] == b[i]) {
			w[i] = min(w[i-1] * 2 - 1, BIG);
		} else if (a[i] == 'a' && b[i] == 'b') {
			w[i] = min(w[i-1] * 2, BIG);
		} else {
			w[i] = min(w[i-1] * 2 - 2, BIG);
		}
	}
	d[n] = min(k, w[n]);
	for (int i=n-1; i>=1; i--) {
		d[i] = min({d[i+1], w[i]}); 
	}
	cout << accumulate(d+1, d+n+1, 0ll) << '\n';
}