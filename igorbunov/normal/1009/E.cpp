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

int MOD = 998244353;

signed main() {
	int n;
	cin >> n;

	vector<int> arr(n);

	vector<int> pows(n, 1);

	for (int i = 1; i < n; i++) {
		pows[i] = (pows[i - 1] * 2) % MOD;
	}

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int now = (pows[n - 1] * arr[0]);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += now;
		ans %= MOD;

		if (i < n - 1) {
			now -= (pows[n - 2 - i] * arr[i]) % MOD;
			now += (pows[n - 2 - i] * arr[i + 1]) % MOD;
		}

		while (now < 0) {
			now += MOD;
		}
	}

	cout << ans;


}