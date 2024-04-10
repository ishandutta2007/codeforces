#include <bits/stdc++.h>
using namespace std;

// 8th degree if you want to avoid FP

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll vb, vs;
ll x[105];
ll xt, yt;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> vb >> vs;
	for (int i=1; i<=n; i++)
		cin >> x[i];
	cin >> xt >> yt;

	int i = 0;
	ld opt = 1e50;

	for (int j=2; j<=n; j++) {
		ld curr = (ld)x[j] / vb;
		curr += sqrt((ld)yt*yt + (ld)(x[j] - xt) * (x[j] - xt)) / vs;

		if (abs(curr - opt) < 1e-12) {
			if (abs(x[j] - xt) < abs(x[i] - xt)) {
				i = j;
				opt = curr;
			}
		} else if (opt > curr) {
			i = j;
			opt = curr;
		}
	}

	cout << i << '\n';
}