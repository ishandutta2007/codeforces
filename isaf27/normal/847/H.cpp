#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int INF = 1e18;

const int MAXN = 1e5 + 1;

int a[MAXN];
int p1[MAXN];
int pref[MAXN];

int p2[MAXN];
int suf[MAXN];

int32_t main()
{   /*
    #define fname "test"
    freopen(fname".in", "r", stdin);
    freopen(fname".out", "w", stdout); /**/

    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    p1[0] = a[0];
    pref[0] = 0;
    for (int i = 1; i < n; i++) {
        p1[i] = max(p1[i - 1] + 1, a[i]);
        pref[i] = pref[i - 1] + p1[i] - a[i];
    }

    p2[n - 1] = a[n - 1];
    suf[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        p2[i] = max(p2[i + 1] + 1, a[i]);
        suf[i] = suf[i + 1] + p2[i] - a[i];
    }

    int res = INF;
    for (int i = 0; i < n; i++) {
        res = min(res, suf[i] + pref[i] - min(p1[i], p2[i]) + a[i]);
    }

    cout << res << endl;

    return 0;
}