#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
 
#pragma GCC_OPTIMIZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int a = 340;

	vector<vector<int>> dp(350, vector<int>(350));

	vector<int> arr(500000);
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int type;
		cin >> type;

		if (type == 1) {
			int x, y;
			cin >> x >> y;
			for (int j = 1; j < 350; j++) {
				int k = x % j;
				dp[j][k] += y;
			}
			arr[x - 1] += y;
		} else {
			int x, y;
			cin >> x >> y;

			if (x < 350) {
				cout << dp[x][y] << endl;
			} else {
				int now = y - 1;
				int ans = 0;
				while (now < 0) {
					now += x;
				}
				while (now < 500000) {
					ans += arr[now];
					now += x;
				}
				cout << ans << endl;
			}
		}
	}
}