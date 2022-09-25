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

    int n;
    string s;
    while (cin >> n >> s) {
        bool ok = 0;
        for (int step = 1; step < n; step++) {
            for (int start = 0; start < n; start++) {
                bool cok = 1;
                for (int j = 0; j < 5; j++) {
                    cok &= start + j * step < n && s[start + j * step] == '*';
                }
                ok |= cok;
            }
        }
        cout << (ok ? "yes" : "no") << endl;
    }

	return 0;
}