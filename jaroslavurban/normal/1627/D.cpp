#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int M = 1e6;

void ProGamerMove() {
	int n;
	cin >> n;
	vector<int> in(M + 1);
	for (int v, i = 0; i < n; ++i) {
		cin >> v;
		in[v] = true;
	}
	for (int v = M; v >= 1; --v) {
		if (in[v]) continue;
		int cur = 0;
		for (int mul = 2; mul * v <= M; ++mul)
			if (in[v * mul])
				cur = __gcd(cur, mul);
		if (cur == 1) in[v] = true;
	}
	cout << accumulate(in.begin(), in.end(), 0) - n << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
//	cin >> tc;
	while (tc--) ProGamerMove();
}