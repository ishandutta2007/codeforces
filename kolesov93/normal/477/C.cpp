#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

const int N = 3022;
int f[N][N], g[N];
int mn[N];
int ans[N];
int cans[N];

int main() {
    string s, w;
    cin >> s >> w;
    int n = s.size();
    int m = w.size();

    memset(f, 63, sizeof(f));
    memset(g, 63, sizeof(g));
    memset(mn, 63, sizeof(mn));
    memset(ans, 63, sizeof(ans));
    for (int i = 0; i < n; ++i) {
        for (int j = i; j >= 0; --j) {
            int pos = j % m;
            if (s[i] == w[pos]) {
                if (j == 0) {
                    f[i][j] = 0;
                } else {
                    if (pos == 0) {
                        f[i][j] = g[j - 1];
                    } else {
                        f[i][j] = min(i + mn[j - 1], 33333);
                    }
                }
                mn[j] = min(mn[j], f[i][j] - i - 1);
                g[j] = min(g[j], f[i][j]);
                ans[(j + 1) / m] = min(ans[(j + 1) / m], f[i][j]);
                //cout << i << " " << j << ": " << f[i][j] << endl;
            }
        }
    }

    for (int i = 0; i <= n; ++i) {
        int lim = n - i * m;
        for (int j = ans[i]; j <= lim; ++j) cans[j] = max(cans[j], i);
    }

    for (int i = 0; i <= n; ++i) {
        cout << cans[i] << " ";
    }
    cout << endl;

    return 0;
}