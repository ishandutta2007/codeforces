#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n; cin >> n;
	array<int, 10> diffs{};
	for (int b, d, i = 0; i < n; ++i) cin >> b >> d, --d, diffs[d] = max(diffs[d], b);
	if (count(diffs.begin(), diffs.end(), 0)) cout << "MOREPROBLEMS\n";
	else cout << accumulate(diffs.begin(), diffs.end(), 0) << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}