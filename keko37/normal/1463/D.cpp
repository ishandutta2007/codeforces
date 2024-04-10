#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 200005;

int t, n;
int a[MAXN], b[MAXN], ok[MAXN * 2], val[MAXN * 2];

bool check_mn (int k) {
    for (int i = 1; i <= 2 * n; i++) val[i] = 0;
    for (int i = 1; i <= k; i++) {
        val[a[i]] = 1;
        val[b[n + 1 - i]] = -1;
    }
    int sum = 0;
    for (int i = 1; i <= 2 * n; i++) {
        sum += val[i];
        if (sum < 0) return 0;
    }
    return 1;
}

bool check_mx (int k) {
    for (int i = 1; i <= 2 * n; i++) val[i] = 0;
    for (int i = 1; i <= n - k; i++) {
        val[b[i]] = 1;
        val[a[n + 1 - i]] = -1;
    }
    int sum = 0;
    for (int i = 1; i <= 2 * n; i++) {
        sum += val[i];
        if (sum < 0) return 0;
    }
    return 1;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            ok[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            ok[a[i]] = 1;
        }
        int ind = 1;
        for (int i = 1; i <= 2 * n; i++) {
            if (ok[i] == 0) b[ind] = i, ind++;
        }

        int lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;
            if (check_mn(mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        int rig = lo;

        lo = 0, hi = n;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (check_mx(mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        int lef = lo;

        if (lef <= rig) cout << rig - lef + 1 << '\n'; else cout << "0\n";
    }
    return 0;
}