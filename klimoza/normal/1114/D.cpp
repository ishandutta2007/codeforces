#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;

//vector<vector<int>> col;
//vector<int> cnt;
vector<int> a;
int n, sz;

int ans() {
	vector<vector<int>> dp(sz);
	for (int i = 0; i < sz; i++) dp[i].resize(sz - i + 1);
	for (int len = 1; len <= sz; len++) {
		for (int l = 0; l < sz - len + 1; l++) {
			if (len == 1) dp[l][len] = 0;
			else if (len == 2) {
				if (a[l] == a[l + 1]) dp[l][len] = 0;
				else dp[l][len] = 1;
			}
			else if (a[l] == a[l + len - 1]) {
				dp[l][len] = dp[l + 1][len - 2] + 1;
			}
			else {
				dp[l][len] = min(dp[l + 1][len - 1], dp[l][len - 1]) + 1;
			}
			//cout << len << " " << l << " " << dp[l][len] << endl;
		}
	}
	return dp[0][sz];
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i]; t[i]--;
		if (i == 0 || t[i] != t[i - 1]) a.push_back(t[i]);
	}
	sz = a.size();
	n = 5000;
	//col.resize(n);
	//cnt.resize(sz);
	//for (int i = 0; i < sz; i++) {
	//	//cout << a[i] << endl;
	//	col[a[i]].push_back(i);
	//}
	//cout << "fel\n";
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < col[i].size() / 2; j++) {
			cout << col[i][j] << " " << col[i][col[i].size() - j - 1] << endl;
			for (int k = col[i][j]; k <= col[i][col[i].size() - j - 1]; k++) {
				cnt[k]++;
			}
		}
	}
	int maxi = 0;
	for (int i = 0; i < sz; i++) {
		maxi = max(maxi, cnt[i]);
	}*/
	cout << ans() << endl;
	//system("pause");
	return 0;
}