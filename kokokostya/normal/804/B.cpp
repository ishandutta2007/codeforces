#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
#include <iomanip>
#include <map>
#include <stack>
#include <bitset>
#include <deque>
#include <unordered_map>

using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	string s;
	cin >> s;
	int cnt = 0;
	int ans = 0;
	vector<int> dp(s.length() + 1);
	dp[0] = 0;
	for (int i = 1; i <= s.length(); i++)
		dp[i] = (2 * dp[i - 1] + 1) % mod;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'a')
			cnt++;
		else {
			ans = (ans + dp[cnt]) % mod;
		}
	}
	cout << ans;
	return 0;
}