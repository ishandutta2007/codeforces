#include <bits/stdc++.h>
using namespace std;

const int N = 100005, MX = 10000;

int n, cnt, cpr = 0;
bool pr[N], chk[N];

int ask(int u) {
    cout << "A " << u << endl;
    int ret; cin >> ret; return ret;
}

void remove(int a) {
    cout << "B " << a << endl;
    int ret; cin >> ret;
    for (int i = a; i <= n; i += a) {
        if (chk[i]) {
            cnt--;
        }
        chk[i] = false;
    }
}

int lg(int u) {
    int cnt = 0, tmp = 1;
    while (1LL * tmp * u <= n) {
        cnt++;
        tmp *= u;
    }
    return cnt;
}

int pw(int u, int v) {
    int tmp = 1;
    while (v--) {
        tmp *= u;
    }
    return tmp;
}

int bs(int u) {
    int l = 1, r = lg(u);
    while (l <= r) {
        int m = (l + r) / 2;
        if (ask(pw(u, m)) == 1) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return pw(u, r);
}

void solve(int l, int r) {
    int cur = 1;
    for (int i = l; i <= r; i++) {
        if (pr[i]) {
            cur *= bs(i);
        }
    }
    for (int i = r + 1; i <= n; i++) {
        if (pr[i]) {
            int cx = 0;
            for (int j = i; j <= n; j += i) {
                cx += chk[j];
            }
            if (ask(i) > cx) {
                cur *= i;
            }
        }
    }
    cout << "C " << cur << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n; cnt = n;
    fill(chk + 1, chk + n + 1, true);
    fill(pr + 2, pr + n + 1, true);
    int l = 2, r = 2;
    int prv = 0, tot = 0;
    for (int i = 2; i <= n; i++) {
        if (pr[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                pr[j] = false;
            }
            cpr++;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (pr[i]) {
            int st = __lg(lg(i)) + 1;
            if (prv + tot + (st + 1) + 1 + cpr > MX) {
                tot = 0; prv++;
                if (ask(1) > cnt) {
                    solve(l, r);
                    return 0;
                }
                l = i;
            }
            remove(i);
            r = i;
            tot += st; prv++; cpr--;
        }
    }
    solve(l, r);
}