#include<bits/stdc++.h>

using namespace std;

typedef long long llint;

const int MAXN = 200005;

llint q, n, x, a, y, b, k;
llint p[MAXN];

bool check (int br) {
    llint cxy = 0, cx = 0, cy = 0;
    for (int i = 1; i <= br; i++) {
        if (i % a == 0 && i % b == 0) {
            cxy++;
        } else if (i % a == 0) {
            cx++;
        } else if (i % b == 0) {
            cy++;
        }
    }
    llint sum = 0;
    for (int i=1; i<=br; i++) {
        if (cxy > 0) {
            sum += p[i] * (x + y) / 100;
            cxy--;
        } else if (cx > 0) {
            sum += p[i] * x / 100;
            cx--;
        } else if (cy > 0) {
            sum += p[i] * y / 100;
            cy--;
        }
        if (sum >= k) return 1;
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while (q--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> p[i];
        }
        sort(p + 1, p + n + 1);
        reverse(p + 1, p + n + 1);
        cin >> x >> a >> y >> b >> k;
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        if (!check(n)) {
            cout << -1 << endl;
            continue;
        }
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        cout << lo << endl;
    }
    return 0;
}