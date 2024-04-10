#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, l;
	string s;
	cin >> n >> s;
	s = string(" ") + s;

	l = s.size() - 1;

	vector<long long> dp(l+1, 3'000'000'000'000'000'000ll);

	dp[0] = 0;
	for (int i=1; i<=l; i++) {
		// gde mi se zavrsava prethodna celina?
		for (int j=0; j<i; j++) {
			// [j+1, .. i] mora da nema vodece nule i da bude manji ili jednak n
			long long val = 0;
			if (s[j+1] == '0' && j+1 < i) {
				continue;
			}

			for (int k=j+1; k<=i; k++) {
				val = 10*val + s[k] - '0';
				if (val >= n) {
					val = n;
				}
			}

			if (val < n) {
				double kandidat = dp[j] * 1.0 * n + val;
				if (kandidat > 2e18) {
					continue;
				}
				dp[i] = min(dp[i], dp[j] * n + val);
			}
		}
	}

	cout << dp[l];
}