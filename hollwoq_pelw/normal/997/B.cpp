#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

#define int long long

void solve_case() {
	int n, res = 0;
	cin >> n;

	for (int c4 = 0; c4 < 9; c4 ++) {
		for (int c9 = 0; c9 < 9; c9++) {
			if (c4 && c9 >= 5) continue ;
			if (n >= c4 + c9)
				res += n - c4 - c9 + 1;
		}
	}

	cout << res;
}