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
	int n;
	cin >> n;
	vector<int> arr(n);
	int ans = 0LL;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int now1 = 0LL;
		int b = 1LL;
		reverse(s.begin(), s.end());

		for (int j = 0; j < s.size(); j++) {
			now1 += (long long)(s[j] - '0') * b;
			b *= 100LL;
			b %= 998244353LL;
			now1 %= 998244353LL;
		}

		ans += now1 * n;
		ans %= 998244353;

		now1 = 0LL;
		b = 10LL;

		for (int j = 0; j < s.size(); j++) {
			now1 += (long long)(s[j] - '0') * b;
			b *= 100;
			b %= 998244353LL;
			now1 %= 998244353LL;
		}

		ans += now1 * n;
		ans %= 998244353LL;
	}

	cout << ans;
}