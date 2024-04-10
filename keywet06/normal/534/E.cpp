#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
using vec = vector<int>;

int64 n, m;
vec a, b;
vec gist;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    cin >> m;
    b.resize(m);
    gist.assign(n, 0);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
        gist[b[i] - 1] += 1;
    }

    int64 dist;
    if (n == 2) {
        dist = a[1] - a[0];
        cout << dist * (m - 1) << endl;
        return 0;
    }

    dist = 0;
    int64 mod = n + n - 2;
    int64 ob = m / mod;
    for (int i = 0; i < n; ++i) gist[i] -= (2 * ob);
    gist[0] += ob;
    gist[n - 1] += ob;

    if (m % mod == 0) {
        int fl = 0;
        int dd = a[1] - a[0];
        for (int i = 1; i < n; ++i)
            if (a[i] - a[i - 1] != dd) fl = 1;
        if (fl)
            cout << "-1" << endl;
        else {
            dist = 2 * (a[n - 1] - a[0]);
            int64 add = dist * ob;
            add -= dd;
            cout << add << endl;
        }
        return 0;
    }

    dist = 2 * (a[n - 1] - a[0]);
    int64 add = dist * ob;
    if (m % mod == 1) {
        cout << add << endl;
        return 0;
    }

    if (gist[0] == 1 && gist[n - 1] == 1) {
        int ind = 1;
        while (gist[ind] == 2) ++ind;
        int ind2 = n - 2;
        while (gist[ind2] == 2) --ind2;
        add += dist;
        for (int j = ind - 1; j <= ind2; ++j) {
            int64 ww = (a[j + 1] - a[j]);
            add -= ww;
        }
        cout << add << endl;
    } else if (gist[0] == 0 && gist[n - 1] == 0) {
        int ind = 1;
        while (gist[ind] == 0) ++ind;
        int ind2 = n - 2;
        while (gist[ind2] == 0) --ind2;
        for (int j = ind; j < ind2; ++j) {
            int64 ww = (a[j + 1] - a[j]);
            add += ww;
        }
        cout << add << endl;
    } else if (gist[0] == 1 && gist[n - 1] == 0) {
        int ind = n - 2;
        while (gist[ind] == 0) --ind;
        if (gist[ind] == 2) {
            for (int j = 0; j < ind; ++j) {
                int64 ww = (a[j + 1] - a[j]);
                add += ww;
                add += ww;
            }
            cout << add << endl;
        } else {
            if (gist[1] == 1) {
                for (int j = 0; j < ind; ++j) {
                    int64 ww = (a[j + 1] - a[j]);
                    add += ww;
                }
                cout << add << endl;
            } else {
                int ind2 = ind;
                while (gist[ind2] == 1) --ind2;
                for (int j = 0; j < ind2; ++j) {
                    int64 ww = (a[j + 1] - a[j]);
                    add += ww;
                    add += ww;
                }
                for (int j = ind2; j < ind; ++j) {
                    int64 ww = (a[j + 1] - a[j]);
                    add += ww;
                }
                cout << add << endl;
            }
        }
    } else if (gist[0] == 0 && gist[n - 1] == 1) {
        int ind = 1;
        while (gist[ind] == 0) ++ind;
        if (gist[ind] == 2) {
            for (int j = ind; j < n - 1; ++j) {
                int64 ww = (a[j + 1] - a[j]);
                add += ww;
                add += ww;
            }
            cout << add << endl;
        } else {
            if (gist[n - 2] == 1) {
                for (int j = ind; j < n - 1; ++j) {
                    int64 ww = (a[j + 1] - a[j]);
                    add += ww;
                }
                cout << add << endl;
            } else {
                int ind2 = ind;
                while (gist[ind2] == 1) ++ind2;
                for (int j = ind; j < ind2; ++j) {
                    int64 ww = (a[j + 1] - a[j]);
                    add += ww;
                }
                for (int j = ind2; j < n - 1; ++j) {
                    int64 ww = (a[j + 1] - a[j]);
                    add += ww;
                    add += ww;
                }
                cout << add << endl;
            }
        }
    }

    return 0;
}