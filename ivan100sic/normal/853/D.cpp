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

int n;
int dp[2][41];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;

	memset(dp, 63, sizeof(dp));
	dp[0][0] = 0;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		x /= 100;

		auto ol = dp[1 - i % 2];
		auto nu = dp[i % 2];

		memset(nu, 63, sizeof(dp[0]));

		/* placam x u kesu. Na karticu mi leze x/10 */
		int x10 = x / 10;
		for (int i=0; i<=40-x10; i++) {
			nu[i + x10] = ol[i] + x;
		}

		/* placam strogo manje od x u kesu, sa kartice mi skidaju x - p */

		for (int p=0; p<x; p++) {
			for (int i=x-p; i<=40; i++) {
				nu[i - x + p] = min(nu[i - x + p], ol[i] + p);
			}
		}
	}

	cout << *min_element(dp[n % 2], dp[n % 2] + 41) * 100ll;
}