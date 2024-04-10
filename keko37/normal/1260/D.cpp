#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

int m, n, k, t;
int a[MAXN], lef[MAXN], rig[MAXN], d[MAXN], p[MAXN];

bool check (int br) {
    if (br == 0) return 1;
    int lim = a[m - br];
    memset(p, 0, sizeof p);
    for (int i = 0; i < k; i++) {
        if (d[i] <= lim) continue;
        p[lef[i] - 1]++; p[rig[i]]--;
    }
    int res = n + 1;
    for (int i = 0; i <= n; i++) {
        if (i) p[i] += p[i - 1];
        if (p[i]) res += 2;
    }
    return res <= t;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> n >> k >> t;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> lef[i] >> rig[i] >> d[i];
    }
    sort(a, a + m);
    int lo = 0, hi = m;
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        if (check(mid)) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }
    cout << lo;
    return 0;
}