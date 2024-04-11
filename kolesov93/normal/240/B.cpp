#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <map>
#include <vector>
#include <queue>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;

typedef long long ll;

const int N = 202;
const int M = 40002;

int n;
int A, B;
int f[N][M][2];
int H[N], S[N];
int* h, *s;

int relax(int i, int j, int k, int val) {
    f[i][j][k] = min(f[i][j][k], val);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> n;
    cin >> A >> B;
    h = H + 1;
    s = S + 1;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        s[i] = h[i];
        if (i) s[i] += s[i - 1];
    }
    h[-1] = h[0];
    s[-1] = 0;

    memset(f, 63, sizeof(f));

    f[0][0][0] = 0;
    f[0][0][1] = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= s[i]; ++j) {
               bool canr = (A - j) >= h[i];
               bool canb = (B - (s[i - 1] - j) >= h[i]);

            if (canr) {
                relax(i + 1, j + h[i], 0, f[i][j][0]);
                relax(i + 1, j + h[i], 0, f[i][j][1] + min(h[i], h[i - 1]));
            }
            if (canb) {
                relax(i + 1, j, 1, f[i][j][1]);
                relax(i + 1, j, 1, f[i][j][0] + min(h[i], h[i - 1]));
            }
        }

    int ans = f[n][0][0];
    for (int i = 0; i <= s[n - 1]; ++i) {
        ans = min(ans, min(f[n][i][0], f[n][i][1]));
    }
    if (ans > s[n - 1]) {
        puts("-1");
        return 0;
    }
    cout << ans << endl;

    return 0;
}