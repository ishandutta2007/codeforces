#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	vector<int> c(n), add(n + 1), res(n);
	for (int& v: c) cin >> v;
	int ones = 0, cur = 0;
	for (int i = 0; i < n; ++i) {
		if (cur < c[i - ones]) { // 1
			if (ones) {
				++cur;
				add[i] -= 1;
				add[i] += i + 1;
			} else cur += i + 1;
			add[i + 1] -= i + 1;
			res[i] = 1;
			++ones;
		} else {
			++cur;
			add[i + 1] -= 1;
			cur += add[i - ones + 1];
		}
	}
	for (int v : res) cout << v << " "; cout << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}