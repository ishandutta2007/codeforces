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

int MOD =  998244353LL;

bool comp(string a, string b) {
	return a.size() < b.size();
}

signed main() {
	int n;
	cin >> n;
	//cout <<  + 132 + 1425 + + 435 << endl;
	vector<string> arr(n);
	int ans = 0LL;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end(), comp);
	vector<int> count1(11);
	for (int i = 0; i < n; i++) {
		string s = arr[i];

		int now = 0;
		int b1 = 1;

		for (int j = 0; j < s.size(); j++) {
			b1 *= 100;
			b1 %= MOD;
		}

		for (int j = 0; j < s.size(); j++) {
			now *= 10;
			now += s[j] - '0';
			b1 = 1;

			for (int k = 0; k < s.size() - j - 1; k++) {
				b1 *= 100;
				b1 %= MOD;
			}

			b1 %= MOD;

			ans += now * b1 * count1[s.size() - j - 1] * 2;
			ans %= MOD;
		}

		reverse(s.begin(), s.end());

		b1 = 1LL;
		now = 0;

		for (int i = 0; i < s.size(); i++) {
			now += (s[i] - '0') * b1;
			b1 *= 100LL;

			b1 %= MOD;

			ans += now * count1[i + 1];
			ans %= MOD;
		}
		ans += now * (n - i - 0);
		ans %= MOD;

		now = 0LL;
		b1 = 10LL;

		for (int i = 0; i < s.size(); i++) {
			now += (s[i] - '0') * b1;
			b1 *= 100LL;
			ans += now * count1[i + 1];
			ans %= MOD;
			b1 %= MOD;
			now %= MOD;
		}
		//cout << ans << " ";
		ans += now * (n - i - 0);
		ans %= MOD;
		count1[s.size()]++;
		//cout << ans << " ";
	}

	for (int i = 0; i < 10; i++) {
		count1[i] = 0;
	}
	cout << ans;
}