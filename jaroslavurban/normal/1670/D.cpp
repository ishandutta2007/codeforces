#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

// views::zip, ranges::sort

typedef long long ll;
typedef long double ld;

vector<int> sum;

void ProGamerMove() {
	int n; cin >> n;
	cout << int(lower_bound(sum.begin(), sum.end(), n) - sum.begin()) + 1 << '\n';
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	sum.push_back(0);
	while (sum.back() < int(1e9)) sum.push_back(sum.back() + 2 * ((2 * sum.size() + 2) / 3));
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}