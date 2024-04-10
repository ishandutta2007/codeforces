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
 
#pragma GCC_OPTIMAZE("ofast")
 
using namespace std;
 

#define int long long
#define endl "\n"

signed main() {
	string t, s;
	cin >> s >> t;

	int n = s.size();
	int m = t.size();

	vector<int> dp_l(m, -1);
	vector<int> dp_r(m, -1);

	int now = 0;
	for (int i = 0; i < n; i++) {
		if (now < m && s[i] == t[now]) {
			dp_l[now] = i;
			now++;
		}
	}

	now = m - 1;

	for (int i = n - 1; i >= 0; i--) {
		if (now >= 0 && t[now] == s[i]) {
			dp_r[now] = i;
			now--;
		}
	} 

	int ans = 0;

	ans = max(ans, n - 1 - dp_l[m - 1]);
	ans = max(ans, dp_r[0]);

	for (int i = 0; i < m - 1; i++) {
		if (dp_l[i] != -1 && dp_r[i + 1] != -1) {
			ans = max(ans, dp_r[i + 1] - dp_l[i] - 1);
		}
	}

	cout << ans;

}