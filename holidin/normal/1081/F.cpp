#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1;

int d[N], n, a[N], cnt = 0;

int get(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int j;
    cin >> j;
    return j;
}

int ge(int l, int r) {
    if (rand() % 2)
        for (int i = l; i <= n; ++i)
            a[i] = 1 - a[i];
    else
        for (int i = 1; i <= r; ++i)
            a[i] = 1 - a[i];
    int ans = 0;
    for (int i = 1; i <= n; ++i)
        ans += a[i];
    return ans;
}

bool get_ans() {
    cout << "! ";
    for (int i = 1; i <= n; ++i)
        cout << d[i];
}

int get_st() {
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        t += a[i];
    }
    return t;
}

void solve0(int t) {
    int i, j;
    int lv = 0;
    for (i = 1; i <= n; ++i) {
        int xp = t, x;
        int f1 = 0, f2 = 0, f3 = 0;
        while (!(f2 == 1 && f3 == 0)) {
            x = get(i, i);
            f2 = 1 - f2;
            if (abs(x - xp) % 2 == i % 2)
                f1 = 1 - f1;
            else
                f3 = 1 - f3;
            xp = x;
        }
        if (x - t - lv== 1)
            d[i] = 0;
        else
            d[i] = 1;
        while (!(f2 == 0 && f3 == 0)) {
            x = get(i, i);
            f2 = 1 - f2;
            if (abs(x - xp) % 2 == i % 2)
                f1 = 1 - f1;
            else
                f3 = 1 - f3;
            xp = x;
        }
        lv = lv + 1 - 2 * d[i];
    }
}

void solve1(int t) {
    int i, x, j;
    while (true) {
        x = get(2, n);
        if (abs(t - x) % 2 == n % 2)
            get(1, n);
        else
            break;
    }
    int bl = n - 2 * t;
    if ((t + bl) - x == 1)
        d[1] = 0;
    else
        d[1] = 1;
    int xp = x;
    while (true) {
        x = get(2, n);
        if (abs(xp - x) % 2 == n % 2)
            get(1, n);
        else
            break;
    }
    int lv = 0;
    for (i = 2; i <= n; ++i) {
        int xp = t, x;
        int f1 = 0, f2 = 0, f3 = 0;
        while (!(f2 == 1 && f3 == 0)) {
            x = get(i - 1, i);
            f2 = 1 - f2;
            if (abs(x - xp) % 2 == i % 2)
                f1 = 1 - f1;
            else
                f3 = 1 - f3;
            xp = x;
        }
        if (xp - t - lv == 0)
            d[i] = 1 - d[i - 1];
        else
            d[i] = d[i - 1];
        while (!(f2 == 0 && f3 == 0)) {
            x = get(i - 1, i);
            f2 = 1 - f2;
            if (abs(x - xp) % 2 == i % 2)
                f1 = 1 - f1;
            else
                f3 = 1 - f3;
            xp = x;
        }
        t = x;
        lv = lv + 1 - 2 * d[i - 1];
    }
}

int main() {
    int i, j, t, x;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> t;
    if (n == 1) {
        cout << "! " << t;
        return 0;
    }
    //t = get_st();
    rand();
    int bl = n - 2 * t;
    int lv = 0;
    if (n % 2 == 0)
        solve0(t);
    else
        solve1(t);
    cout << "! ";
    for (i = 1; i <= n; ++i)
        cout << d[i];
    cout << endl;
}