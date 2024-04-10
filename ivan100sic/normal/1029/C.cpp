#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int l[300005], r[300005], pl[300005], pr[300005], n;
int sl[300005], sr[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	pl[0] = sr[n+1] = 0;
	pr[0] = sr[n+1] = 1'123'123'123;

	for (int i=1; i<=n; i++) {
		cin >> l[i] >> r[i];
		pl[i] = max(pl[i-1], l[i]);
		pr[i] = min(pr[i-1], r[i]);
	}

	for (int i=n; i>=1; i--) {
		sl[i] = max(sl[i+1], l[i]);
		sr[i] = min(sr[i+1], r[i]);
	}

	int sol = 0;

	for (int i=1; i<=n; i++) {
		int L = max(pl[i-1], sl[i+1]);
		int R = min(pr[i-1], sr[i+1]);

		sol = max(sol, R-L);
	}

	cout << sol;
}