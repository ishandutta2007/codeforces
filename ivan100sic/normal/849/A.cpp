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

int a[105], n;

bool dp[105][2];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		a[i] %= 2;
	}

	dp[0][0] = true;

	for (int i=1; i<=n; i++) {
		for (int j=i; j>0; j-=2) {
			if (a[i] + a[j] == 2) {
				dp[i][0] |= dp[j-1][1];
				dp[i][1] |= dp[j-1][0];
			}
		}
	}

	cout << (dp[n][1] ? "Yes" : "No");


}