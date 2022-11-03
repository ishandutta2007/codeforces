#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <complex>
#include <bitset>
#include <iomanip>

using namespace std;

int gcd(int a, int b) {
	if (!a)
		return b;
	return gcd(b % a, a);
}

int _gcd(int a, int b, int & x, int & y) {
	if (a == 0) {
		x = 0; y = 1;
		return b;
	}
	int x1, y1;
	int d = _gcd(b % a, a, x1, y1);
	x = y1 - (b / a) * x1;
	y = x1;
	return d;
}

int to(int x, int y, int m) {
	int a, b;
	int f = _gcd(x, m, a, b);
	return ((y / f) * 1ll * ((a % m) + m)) % m;
}

const int MX = 2e5 + 10;
vector < int > which[MX];
int cn[MX], dp[MX], pr[MX];

int main(){
	iostream::sync_with_stdio(0);
	
	int m, k;
	cin >> k >> m;

	set < int > all;
	for (int i = 0; i < m; i++)
		all.insert(i);
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		all.erase(x);
	}

	fill(cn, cn + m, 0);
	for (int i : all) {
		int d = gcd(i, m) % m;
		cn[d]++;
		which[d].push_back(i);
	}

	int mx = -1;
	fill(dp, dp + m, -1e9);
	fill(pr, pr + m, -1);
	if (*all.begin() == 0) {
		dp[0] = 1;
		mx = 0;
	}

	for (int i = m - 1; i > 0; i--) {
		if (!cn[i])
			continue;
		dp[i] = 0;
		if (*all.begin() == 0) {
			dp[i] = dp[0];
			pr[i] = 0;
		}
		for (int j = 2 * i; j < m; j += i) {
			if (dp[j] > dp[i]) {
				dp[i] = dp[j];
				pr[i] = j;
			}
		}
		dp[i] += cn[i];
		if (dp[i] > dp[mx])
			mx = i;
	}

	cout << dp[mx] << '\n';
	vector < int > res;
	while (mx != -1) {
		for (int i : which[mx])
			res.push_back(i);
		mx = pr[mx];
	}
	cout << res[0] << ' ';
	for (int i = 1; i < res.size(); i++)
		cout << to(res[i - 1], res[i], m) << ' ';

	return 0;
}