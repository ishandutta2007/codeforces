#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>
#include <cstdlib>

using namespace std; 

#define ll long long
#pragma comment(linker, "/STACK:64000000")

const int maxn = -1;
const int inf = 1000000007;
const int mod = 1000000007;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

vector<int> getz(string s) {
	int n = s.length();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r) {
			z[i] = min(z[i - l], r - i + 1);
		}
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
	return z;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    
	string a, b;
	while (cin >> a >> b) {
		string s = b + "$" + a;
		vector<int> z = getz(s);
		vector<int> pos;
		for (int i = b.length() + 1; i < (int)s.length(); i++) {
			if (z[i] == b.length()) {
				pos.push_back(i - (int)b.length() - 1);
			}
		}

		int n = a.length(), m = b.length();
		vector<int> dp(n + 1), ss(n + 1);
		dp[0] = 1;
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (i) {
				ss[i] = (ss[i - 1] + ss[i]) % mod;
				dp[i] = (dp[i] + ss[i]) % mod;
			}
			dp[i + 1] = (dp[i + 1] + dp[i]) % mod;
			while (j < (int)pos.size() && pos[j] < i) j++;
			if (j < (int)pos.size() && pos[j] + b.length() <= n) {
				ss[pos[j] + b.length()] = (ss[pos[j] + b.length()] + dp[i]) % mod;
			}
		}
		dp[n] = ((dp[n] + ss[n]) % mod + ss[n - 1]) % mod;
		cout << (dp[n] - 1 + mod) % mod << endl;
	}

    return 0;
}