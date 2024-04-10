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
const int MAXN = -1;
const int MOD = 1; // 1000 * 1000 * 1000 + 7;



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	int m;
	string a;
	while (cin >> m >> a) {
		int n = a.length();

		vector<vector<int> > pos(26);
		for (int i = 0; i < n; i++) {
			pos[a[i] - 'a'].push_back(i);
		}

		vector<int> taken(n);
		for (int c = 0; c < 26; c++) {
			vector<int> ntaken = taken;
			for (int x : pos[c]) {
				ntaken[x] = 1;
			}
			vector<int> s(n);
			s[0] = ntaken[0];
			for (int i = 1; i < n; i++) s[i] = s[i - 1] + ntaken[i];

			bool cok = 1;
			for (int i = 0; i + m <= n; i++) {
				int csum = s[i + m - 1] - (i ? s[i - 1] : 0);
				cok &= csum > 0;
			}
			
			if (!cok) {
				taken = ntaken;
				continue;
			}

			ntaken = taken;
			s[0] = ntaken[0];
			for (int i = 1; i < n; i++) s[i] = s[i - 1] + ntaken[i];

			int last = -1;
			for (int i = 0; i + m <= n; i++) {
				int csum = s[i + m - 1] - (i ? s[i - 1] : 0);
				if (csum > 0 || last >= i) continue;
				int id = pos[c][lower_bound(pos[c].begin(), pos[c].end(), i + m) - pos[c].begin() - 1];
				ntaken[id] = 1;
				last = id;
			}

			vector<char> ans;
			for (int i = 0; i < n; i++) if (ntaken[i]) ans.push_back(a[i]);

			sort(ans.begin(), ans.end());
			string res = "";
			for (char c : ans) res += (char)c;
			cout << res << endl;
			break;
		}
	}

	return 0;
}