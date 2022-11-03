



#define _CRT_SECURE_NO_WARNINGS


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
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

//#define FAST_ALLOCATOR_MEMORY 1e8
#undef LOCAL
//#include "optimization.h"

const int MX = 2e5 + 7;
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 33;
const long long p = 239;
long long arrp[MX];
long long arrp2[MX];
long long sum[26];
long long sum2[26];

int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	set<int> pos[26];
	arrp[0] = 1;
	for (int i = 1; i < MX; i++)
		arrp[i] = (arrp[i - 1] * p) % mod;

	arrp2[0] = 1;
	for (int i = 1; i < MX; i++)
		arrp2[i] = (arrp2[i - 1] * p) % mod2;
	
	for (int i = 0; i < m; i++) {
		pos[s[i] - 'a'].insert(i);
		sum[s[i] - 'a'] = (sum[s[i] - 'a'] + arrp[n - 1 - i]) % mod;
		sum2[s[i] - 'a'] = (sum2[s[i] - 'a'] + arrp2[n - 1 - i]) % mod2;
	}
	int h = 0;
	for (int i = 0; i < m; i++)
		h = (h * p + t[i]) % mod;

	int h2 = 0;
	for (int i = 0; i < m; i++)
		h2 = (h2 * p + t[i]) % mod2;

	vector<int> ans;
	for (int j = 0; j + m <= n; j++) {
		vector<int> pr(26, -1);
		for (int i = 0; i < 26; i++) {
			if (!pos[i].empty()) {
				auto q = pos[i].begin();
				pr[i] = t[(*q) - j] - 'a';
			}
		}
		bool is = 1;
		vector<bool> used(26);
		for (int i = 0; i < 26; i++) {
			if(pr[i] != -1 && pr[pr[i]] != -1)
				is &= (i == pr[pr[i]]);
		}
		for (int i = 0; i < 26; i++) {
			if (pr[i] != -1) {
				if (used[pr[i]])
					is = 0;
				used[pr[i]] = 1;
			}
		}
	
		if (is) {
			long long nh = 0;
			for (int i = 0; i < 26; i++) {
				nh += (sum[i] % mod) * (pr[i] + 'a');
			}

			long long nh2 = 0;
			for (int i = 0; i < 26; i++) {
				nh2 += (sum2[i] % mod2) * (pr[i] + 'a');
			}

			if ((((h * arrp[n - (m + j)]) % mod) == (nh % mod)) 
				&& ((((h2 * arrp2[n - (m + j)]) % mod2) == (nh2 % mod2))))
				ans.push_back(j);
		}
		pos[s[j] - 'a'].erase(j);
		sum[s[j] - 'a'] = (sum[s[j] - 'a'] - arrp[n - 1 - j] + mod) % mod;
		sum2[s[j] - 'a'] = (sum2[s[j] - 'a'] - arrp2[n - 1 - j] + mod2) % mod2;

		if (j + m != n) {
			pos[s[j + m] - 'a'].insert(j + m);
			sum[s[j + m] - 'a'] = (sum[s[j + m] - 'a'] + arrp[n - 1 - (j + m)]) % mod;
			sum2[s[j + m] - 'a'] = (sum2[s[j + m] - 'a'] + arrp2[n - 1 - (j + m)]) % mod2;
		}
	}

	cout << ans.size() << '\n';
	for (int i : ans)
		cout << i + 1 << ' ';

	return 0;
}