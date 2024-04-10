#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int g[5][1000005];
int cal(int m) {
    int k1 = g[1][1];
    int k2 = g[2][1];
    int mmin = 0x3f3f3f3f;
    int ans = 0;
    for (int i = 2; i <= m; i++) {
        if (k1 == 0 && k2 == 0) {
            ans++;
            k1 = g[1][i] ^ 1;
            k2 = g[2][i] ^ 1;
        } else if (k1 == 1 && k2 == 0) {
            ans++;
            k1 = g[1][i];
            k2 = g[2][i] ^ 1;
        } else if (k1 == 0 && k2 == 1) {
            ans++;
            k1 = g[1][i] ^ 1;
            k2 = g[2][i];
        } else {
            k1 = g[1][i];
            k2 = g[2][i];
        }
        if (i == m) {
            if (k1 != 1 || k2 != 1) ans++;
        }
    }
    mmin = min(mmin, ans);
    ans = 1;
    k1 = g[1][1] ^ 1;
    k2 = g[2][1];
    for (int i = 2; i <= m; i++) {
        if (k1 == 0 && k2 == 0) {
            ans++;
            k1 = g[1][i] ^ 1;
            k2 = g[2][i] ^ 1;
        } else if (k1 == 1 && k2 == 0) {
            ans++;
            k1 = g[1][i];
            k2 = g[2][i] ^ 1;
        } else if (k1 == 0 && k2 == 1) {
            ans++;
            k1 = g[1][i] ^ 1;
            k2 = g[2][i];
        } else {
            k1 = g[1][i];
            k2 = g[2][i];
        }
        if (i == m) {
            if (k1 != 1 || k2 != 1) ans++;
        }
    }
    mmin = min(mmin, ans);
    ans = 1;
    k1 = g[1][1];
    k2 = g[2][1] ^ 1;
    for (int i = 2; i <= m; i++) {
        if (k1 == 0 && k2 == 0) {
            ans++;
            k1 = g[1][i] ^ 1;
            k2 = g[2][i] ^ 1;
        } else if (k1 == 1 && k2 == 0) {
            ans++;
            k1 = g[1][i];
            k2 = g[2][i] ^ 1;
        } else if (k1 == 0 && k2 == 1) {
            ans++;
            k1 = g[1][i] ^ 1;
            k2 = g[2][i];
        } else {
            k1 = g[1][i];
            k2 = g[2][i];
        }
        if (i == m) {
            if (k1 != 1 || k2 != 1) ans++;
        }
    }
    mmin = min(mmin, ans);
    ans = 1;
    k1 = g[1][1] ^ 1;
    k2 = g[2][1] ^ 1;
    for (int i = 2; i <= m; i++) {
        if (k1 == 0 && k2 == 0) {
            ans++;
            k1 = g[1][i] ^ 1;
            k2 = g[2][i] ^ 1;
        } else if (k1 == 1 && k2 == 0) {
            ans++;
            k1 = g[1][i];
            k2 = g[2][i] ^ 1;
        } else if (k1 == 0 && k2 == 1) {
            ans++;
            k1 = g[1][i] ^ 1;
            k2 = g[2][i];
        } else {
            k1 = g[1][i];
            k2 = g[2][i];
        }
        if (i == m) {
            if (k1 != 1 || k2 != 1) ans++;
        }
    }
    mmin = min(mmin, ans);
    return mmin;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    if (n > 3 && m > 3) {
        cout << -1;
        return 0;
    }
    if (n <= m) {
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                char c;
                cin >> c;
                g[i][j] = c - '0';
            }
    } else {
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++) {
                char c;
                cin >> c;
                g[i][j] = c - '0';
            }
        swap(n, m);
    }
    int mmin = 0x3f3f3f3f;
    if (n == 1) {
        cout << 0;
        return 0;
    } else if (n == 2) {
        int cnt = 0;
        for (int i = 1; i <= m; i++) {
            if (i & 1) {
                if (g[1][i] + g[2][i] != 1) cnt++;
            } else {
                if (g[1][i] + g[2][i] == 1) cnt++;
            }
        }
        mmin = min(mmin, cnt);
        cnt = 0;
        for (int i = 1; i <= m; i++) {
            if (i & 1) {
                if (g[1][i] + g[2][i] == 1) cnt++;
            } else {
                if (g[1][i] + g[2][i] != 1) cnt++;
            }
        }
        mmin = min(mmin, cnt);
    } else {
        for (int i = 1; i < m; i++) {
            int k1 = g[1][i] + g[2][i] + g[1][i + 1] + g[2][i + 1];
            int k2 = g[2][i] + g[3][i] + g[3][i + 1] + g[2][i + 1];
            if (k1 & 1)
                g[1][i] = 1;
            else
                g[1][i] = 0;
            if (k2 & 1)
                g[2][i] = 1;
            else
                g[2][i] = 0;
        }
        mmin = min(mmin, cal(m - 1));
    }
    cout << mmin << endl;
}