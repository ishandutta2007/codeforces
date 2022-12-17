#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N = 2e5 + 10;
const int LogN = 31;
const int inf = 1e9;

int t[LogN], d[LogN];

void add(int x) {
    for (int i = LogN - 1; i >= 0; --i)
    if ((x & t[i]) > 0) {
        if (d[i] == 0)
            d[i] = x;
        x ^= d[i];
    }
}

int main() {
    int i, j, l, r, q, n, a;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    t[0] = 1;
    for (i = 1; i < LogN; ++i)
        t[i] = t[i - 1] * 2;
    int tek = 0;
    for (i = 0; i < n; ++i) {
        cin >> a;
        tek ^= a;
        add(tek);
    }
    if (tek == 0)
        cout << -1;
    else {
        int ans = 0;
        for (i = 0; i < LogN; ++i)
        if (d[i] != 0)
            ++ans;
        cout << ans;
    }
}