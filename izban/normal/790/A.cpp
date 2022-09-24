#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cassert>
#include <ctime>
#include <map>
#include <math.h>
#include <cstdio>
#include <set>
#include <deque>
#include <memory.h>
#include <queue>

#pragma comment(linker, "/STACK:64000000")
typedef long long ll;

using namespace std;

const int MAXK = -1;
const int MAXN = 1 << MAXK;
const int MOD = 0; // 1000 * 1000 * 1000 + 7;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int n, k;
	while (cin >> n >> k) {
		vector<string> a(n - k + 1);
		for (int i = 0; i < n - k + 1; i++) cin >> a[i];

		set<string> st;
		while (st.size() < k) {
			string s = "";
			s += (char)('A' + rand() % 3);
			for (int i = 0; i < 3; i++) s += (char)('a' + rand() % 3);
			st.insert(s);
		}
		vector<string> names;
		for (string s : st) names.push_back(s);

		vector<int> ans;
		for (int i = 0; i < k - 1; i++) ans.push_back(i);

		for (int i = 0; i < n - k + 1; i++) {
			if (a[i] == "NO") {
				ans.push_back(ans[(int)ans.size() - k + 1]);
			}
			else {
				vector<char> was(k);
				for (int i = 0; i < k - 1; i++) was[ans[(int)ans.size() - 1 - i]] = 1;
				int ch = -1;
				for (int i = 0; i < k; i++) {
					if (!was[i]) {
						assert(ch == -1);
						ch = i;
					}
				}
				assert(ch != -1);
				ans.push_back(ch);
			}
		}
		assert(ans.size() == n);
		for (int i = 0; i < (int)ans.size(); i++) cout << names[ans[i]] << " \n"[i + 1 == (int)ans.size()];
	}

	return 0;
}