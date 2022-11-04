#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int a, b; cin >> a >> b;
	if (a > b) swap(a, b);
	a -= 2;
	vector<int> res = {1, 2};
	for (int it = 0; it < 3; ++it, --b, ++a) {
		for (int i = 1; i * i <= a; ++i) if (a % i == 0) {
			if (b % i == 0) res.push_back(i);
			if (b % (a / i) == 0) res.push_back(a / i);
		}
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	cout << res.size() << " ";
	for (int v : res) cout << v << ' '; cout << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}