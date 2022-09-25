#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long

const int maxn = 3 * (1 << 10);
const int mod = 1000000007;

int n, m;
string s[maxn];

int d[maxn][maxn];

void add(int &a, int b) {
    a += b;
    if (a >= mod) a -= mod;
}

int calc(int s1, int s2, int f1, int f2) {
    memset(d, 0, sizeof(d));
    if (s[s1][s2] == '.') d[s1][s2] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < n - 1 && s[i + 1][j] == '.') add(d[i + 1][j], d[i][j]);
            if (j < m - 1 && s[i][j + 1] == '.') add(d[i][j + 1], d[i][j]);
        }
    }
    return d[f1][f2];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) cin >> s[i];

        ll A = calc(0, 1, n - 2, m - 1);
        ll B = calc(0, 1, n - 1, m - 2);
        ll C = calc(1, 0, n - 2, m - 1);
        ll D = calc(1, 0, n - 1, m - 2);

        cout << ((A * D - B * C) % mod + mod) % mod << endl;
    }

    return 0;
}