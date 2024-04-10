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

const int maxn = 1 << 22;
const int inf = 1e9;
const int mod = 1e9 + 7;

char buf[maxn], s[maxn];
int n, m;
int y[maxn];

vector<int> getz (string s) {
    //cout << s << endl;
	int n = (int)s.length();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	//for (int i = 0; i < (int)z.size(); i++) cout << z[i] << " \n"[i + 1 == (int)z.size()];

	return z;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);

    while (scanf("%d%d\n", &n, &m) == 2) {
        scanf("%s\n", buf);
        int p = strlen(buf);
        for (int i = 0; i < m; i++) scanf("%d", &y[i]), y[i]--;

        memset(s, '*', sizeof(s));
        int last = -1;
        for (int i = 0; i < m; i++) {
            for (int j = max(0, last - y[i] + 1); j < p; j++) {
                s[y[i] + j] = buf[j];
                last = y[i] + j;
            }
        }
        s[n] = 0;

        vector<int> z = getz((string)(buf) + "#" + (string)(s));

        bool ok = 1;
        for (int i = 0; i < m; i++) {
            ok &= z[p + y[i] + 1] >= p;
        }

        int ans = 1;
        for (int i = 0; i < n; i++) if (s[i] == '*') ans = 1LL * ans * 26 % mod;
        if (!ok) ans = 0;
        cout << ans << endl;
    }

	return 0;
}