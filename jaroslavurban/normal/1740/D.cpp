#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(k), in(k);
	for (int& v : a) cin >> v, --v;
	int taken = 0, want = k - 1;
	for (int i = 0; i < k; ++i) {
		in[a[i]] = true;
		++taken;
		if (taken >= n * m - 2) { cout << "TIDAK\n"; return; }
		while (want >= 0 && in[want]) in[want] = false, --want, --taken;
	}
	assert(want == -1);
	cout << "YA\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}