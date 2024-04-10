#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n;
int a[MAXN], pref[MAXN], suf[MAXN], ok_pref[MAXN], ok_suf[MAXN];

bool is_ok (int a, int b, int c, int d) {
    if (b - a < 0) return 0;
    if (c - b + a < 0) return 0;
    if (d - c + b - a != 0) return 0;
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        ok_pref[0] = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = a[i] - pref[i - 1];
            ok_pref[i] = (pref[i] >= 0) && ok_pref[i - 1];
        }
        ok_suf[n + 1] = 1; suf[n + 1] = 0;
        for (int i = n; i >= 1; i--) {
            suf[i] = a[i] - suf[i + 1];
            ok_suf[i] = (suf[i] >= 0) && ok_suf[i + 1];
        }
        if (pref[n] == 0 && ok_pref[n] == 1) {
            cout << "YES\n";
            continue;
        }
        bool ok = 0;
        for (int i = 1; i < n; i++) {
            if (ok_pref[i - 1] && ok_suf[i + 2] && is_ok(pref[i - 1], a[i + 1], a[i], suf[i + 2])) ok = 1;
        }
        if (ok) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}