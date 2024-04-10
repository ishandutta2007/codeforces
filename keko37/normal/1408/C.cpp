#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;
typedef long double ld;

const int MAXN = 100005;

int t, n, L;
ld a[MAXN];

ld get_lef (ld t) {
    ld speed = 1;
    int ind = 0;
    for (int i = 1; i <= n + 1; i++) {
        ld need = (a[ind + 1] - a[ind]) / speed;
        if (t < need) break;
        t -= need;
        speed++;
        ind++;
    }
    if (ind == n + 1) return L;
    return a[ind] + speed * t;
}

ld get_rig (ld t) {
    ld speed = 1;
    int ind = n + 1;
    for (int i = n; i >= 0; i--) {
        ld need = (a[ind] - a[ind - 1]) / speed;
        if (t < need) break;
        t -= need;
        speed++;
        ind--;
    }
    if (ind == 0) return 0;
    return a[ind] - speed * t;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n >> L;
        a[0] = 0; a[n + 1] = L;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ld lo = 0, hi = L;
        for (int i = 0; i < 60; i++) {
            ld mid = (lo + hi) / 2;
            if (get_lef(mid) < get_rig(mid)) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        cout << fixed << setprecision(10) << lo << '\n';
    }
    return 0;
}