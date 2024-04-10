#include <bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
const int N = 400;
const int inf = 2e9;
const int mod = 1e9 + 7;
const int maxN = 2e7 + 1;


int m[N][N];

void run() {
    int n, k, a, b;
    cin >> n >> k;
    if (k % n == 0)
        cout << 0 << "\n";
    else
        cout << 2 << "\n";
    int x = k / n + 1;
    for (int i = 0; i < n; ++i)
    for (int j = 0; j < x - 1; ++j) {
        m[i][(i + j) % n] = 1;
    }
    k %= n;
    for (int i = 0; i < n; ++i)
    if (k > 0) {
        --k;
        m[i][(i + x - 1) % n] = 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << m[i][j];
            m[i][j] = 0;
        }
        cout << "\n";
    }
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
        run();
}