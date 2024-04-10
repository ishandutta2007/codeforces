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

const int maxn = 1 << 21;
const int inf = 1e9;

int n, k;
char buf[maxn];

vector<int> getz (string s) {
	int n = (int)s.length();
	vector<int> z(n);
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	//ios_base::sync_with_stdio(0);
    while (scanf("%d %d\n", &n, &k) == 2) {
        scanf("%s\n", buf);
        string s = buf;

        vector<int> _z = getz(s + "$" + s);
        vector<int> z(n);
        for (int i = 0; i < n; i++) z[i] = _z[i + n + 1];

        vector<int> a(2 * n + 1);
        for (int len = 1; len * k <= n; len++) {
            bool ok = 1;
            for (int j = 1; j < k; j++) {
                ok &= z[len * j] >= len;
            }
            if (!ok) continue;
            a[len * k - 1] += 1;
            a[len * k + min(z[len * k], len)] -= 1;
        }
        string ss = "";
        for (int i = 0; i < n; i++) {
            if (i) a[i] += a[i - 1];
            ss += (a[i] > 0 ? '1' : '0');
        }
        printf("%s\n", ss.c_str());
    }


	return 0;
}