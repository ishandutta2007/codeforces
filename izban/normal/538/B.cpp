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

#pragma comment(linker, "/STACK:50000000")
typedef long long ll;

using namespace std;

const int maxn = -1;
const int inf = 1e9;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);

    string s;
    while (cin >> s) {
        int mx = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) mx = max(mx, s[i] - '0');

        vector<string> ans(mx, s);
        for (int i = 0; i < mx; i++) for (int j = 0; j < n; j++) ans[i][j] = '0';

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < s[i] - '0'; j++) {
                ans[j][i]++;
            }
        }

        vector<int> res(mx);
        for (int i = 0; i < mx; i++) {
            stringstream ss;
            ss << ans[i];
            ss >> res[i];
        }

        cout << res.size() << endl;
        for (int i = 0; i < (int)res.size(); i++) cout << res[i] << " \n"[i + 1 == (int)res.size()];
    }

	return 0;
}