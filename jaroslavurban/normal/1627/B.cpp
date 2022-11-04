#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, m;
	cin >> n >> m;
	vector<int> dist;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			dist.push_back(max(i, n - i - 1) + max(j, m - j - 1));
	sort(dist.begin(), dist.end());
	for (int d : dist) cout << d << " ";
	cout << "\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}