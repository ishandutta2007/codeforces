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
    int n;
    while (cin >> s) {
        n = s.length();
        bool ok = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                string o = "";
                for (int k = 0; k < n; k++) if (k < i || k > j) o += s[k];
                ok |= o == "CODEFORCES";
            }
        }
        cout << (ok ? "YES" : "NO") << endl;
    }

	return 0;
}