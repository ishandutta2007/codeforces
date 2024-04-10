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
    while (cin >> n) {
        vector<string> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<string> b = a;

        int m = 2 * n - 1;
        vector<string> ans(m);
        for (int i = 0; i < m; i++) for (int j = 0; j < m; j++) ans[i] += '.';

        ans[n - 1][n - 1] = 'o';
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == (n - 1) && j == (n - 1)) continue;
                bool ok = 1;

                int dx = i - (n - 1);
                int dy = j - (n - 1);
                for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        if (a[x][y] == 'o') {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                                ok &= a[nx][ny] == 'o' || a[nx][ny] == 'x';
                            }
                        }
                    }
                }
                if (ok) {
                    ans[i][j] = 'x';
                    for (int x = 0; x < n; x++) {
                    for (int y = 0; y < n; y++) {
                        if (a[x][y] == 'o') {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
                                b[nx][ny] = '.';
                            }
                        }
                    }
                }
                }
            }
        }

        bool fail = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (b[i][j] == 'x') fail = 1;

        if (fail) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 0; i < m; i++) cout << ans[i] << endl;
        }

    }

	return 0;
}