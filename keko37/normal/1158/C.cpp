#include<bits/stdc++.h>

using namespace std;

const int MAXN = 500005;

int t, n;
int nxt[MAXN], p[MAXN], prv[MAXN];

int calc_prv (int x) {
    if (prv[x] != -1) return prv[x];
    int res = x - 1;
    while (nxt[res] == x) {
        res = calc_prv(res);
    }
    prv[x] = res;
    return res;
}

void rjesi (int x, int low, int high) {
    p[x] = high;
    int res = x - 1;
    while (nxt[res] == x) {
        rjesi(res, low, low + (res - prv[res]) - 1);
        low += res - prv[res];
        res = prv[res];
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for (int tc = 0; tc < t; tc++) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> nxt[i];
            if (nxt[i] == -1) nxt[i] = i+1;
            prv[i] = -1;
        }
        prv[n+1] = -1;
        if (calc_prv(n+1) != 0) {
            cout << -1 << endl;
            continue;
        }
        rjesi(n+1, 1, n+1);
        for (int i=1; i<=n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
    }
    return 0;
}