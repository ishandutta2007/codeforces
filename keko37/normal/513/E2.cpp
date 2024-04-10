#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 30005;
const int MAXK = 205;
const int INF = 1000000000;

int n, k;
llint a[MAXN];
int nxt[4][2];
int dp[MAXN][MAXK][4][2];

void init () {
    nxt[0][0] = 2; nxt[0][1] = 3;
    nxt[1][0] = 1; nxt[1][1] = 0;
    nxt[2][0] = 2; nxt[2][1] = 3;
    nxt[3][0] = 1; nxt[3][1] = 0;
}

llint calc (int pos, int ost, int tip, int akt) {
    if (ost == 0 && akt == 1) return -INF;
    if (ost == 0) return 0;
    if (pos == n) return -INF;

    if (dp[pos][ost][tip][akt] != -1) return dp[pos][ost][tip][akt];
    llint res = -INF;

    if (akt) {
        llint now = 0;
        if (ost == k || ost == 1) {
            if (tip == 0 || tip == 3) return -INF;
            if (ost == k) {
                if (tip == 1) now = -a[pos]; else now = a[pos];
            } else {
                if (tip == 1) now = a[pos]; else now = -a[pos];
            }
        } else {
            if (tip == 0) now = 2 * a[pos]; else if (tip == 3) now = -2 * a[pos];
        }
        res = calc(pos + 1, ost, tip, 1);
        res = max(res, calc(pos + 1, ost - 1, nxt[tip][0], 0));
        res = max(res, calc(pos + 1, ost - 1, nxt[tip][0], 1));
        res = max(res, calc(pos + 1, ost - 1, nxt[tip][1], 0));
        res = max(res, calc(pos + 1, ost - 1, nxt[tip][1], 1));
        res += now;
    } else {
        res = calc(pos + 1, ost, tip, 0);
        res = max(res, calc(pos + 1, ost, tip, 1));
    }

    return dp[pos][ost][tip][akt] = res;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof dp);
    init();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << max(max(calc(0, k, 1, 0), calc(0, k, 1, 1)), max(calc(0, k, 2, 0), calc(0, k, 2, 1)));
    return 0;
}