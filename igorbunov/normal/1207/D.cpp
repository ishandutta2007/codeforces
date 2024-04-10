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

int MOD = 998244353;

signed main() {
	int n;
	cin >> n;

	int ans = 0;

	vector<int> fact(n + 1, 0);

	fact[0] = 1;

	for (int i = 1; i <= n; i++) {
		fact[i] = fact[i - 1] * i;

		//cout << fact[i] << " ";
		fact[i] %= MOD;
	}

	//cout << endl;
	vector<pair<int, int>> arr(n);

	vector<vector<int>> arr3(n + 1);

	vector<int> arr1(n + 1);
	vector<int> arr2(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;

		arr3[arr[i].first].push_back(arr[i].second);

		arr1[arr[i].first]++;
		arr2[arr[i].second]++;
	}

	int ans1 = 1;

	for (int i = 0; i <= n; i++) {
		ans1 *= fact[arr1[i]];
		ans1 %= MOD;
	}

	ans += ans1;

	int ans2 = 1;

	for (int i = 0; i <= n; i++) {
		ans2 *= fact[arr2[i]];
		ans2 %= MOD;
	}

	ans += ans2;

	int ans3 = 1;
	for (int i = 0; i <= n; i++) {
		sort(arr3[i].begin(), arr3[i].end());

		int sz = 1;

		for (int j = 1; j < arr3[i].size(); j++) {

			if (arr3[i][j] != arr3[i][j - 1]) {
				ans3 *= fact[sz];
				ans3 %= MOD;
				sz = 1;
			} else {
				sz++;
			}
		} 

		ans3 *= fact[sz];
		ans3 %= MOD;
	}

	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i++) {
		//cout << arr[i].first << " " << arr[i].second << endl;
	}

	for (int i = 1; i < n; i++) {
		if (arr[i].second < arr[i - 1].second) {
			ans3 = 0;
			break;
		}
	}

	ans3 += MOD * 5;
	ans3 %= MOD;

	ans -= ans3;

	//cout << ans1 << " " << ans2 << " " << ans3 << endl;
	cout << (fact[n] - ans + MOD * 5) % MOD << " ";
}