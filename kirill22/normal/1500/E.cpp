#include<bits/stdc++.h>

using namespace std;

const int N = 400000;
long long s[N], a[N], sum = 0;
int type[N], cnt[4 * N], n, q, M, tmp;
long long t[4 * N], d[4 * N], f[4 * N];
vector<long long> z;

int id(int v, int l, int r, int x) {
    if (l + 1 == r) {
        if (cnt[v] <= x) {
            return M;
        } else {
            return l;
        }
    }
    int m = (l + r) / 2;
    if (cnt[v * 2 + 1] > x) {
        return id(v * 2 + 1, l, m, x);
    } else {
        return id(v * 2 + 2, m, r, x - cnt[v * 2 + 1]);
    }
}

int id(int x) {
    return id(0, 0, M, x);
}

void update(int v, int l, int r, int x, int y) {
    if (l + 1 == r) {
        cnt[v] = y;
        if (y == 1) {
            sum += z[l];
        } else {
            sum -= z[l];
        }
        t[v] = 1ll * cnt[v] * z[l];
        d[v] = f[v] = t[v];
        return;
    }
    int m = (l + r) / 2;
    if (x < m) {
        update(v * 2 + 1, l, m, x, y);
    } else {
        update(v * 2 + 2, m, r, x, y);
    }
    cnt[v] = cnt[v * 2 + 1] + cnt[v * 2 + 2];
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
    d[v] = d[v * 2 + 2] + d[v * 2 + 1] + 1ll * cnt[v * 2 + 2] * t[v * 2 + 1];
    f[v] = f[v * 2 + 1] + f[v * 2 + 2] + 1ll * cnt[v * 2 + 1] * t[v * 2 + 2];
}

long long get_sum(int v, int l, int r, int x) {
    if (cnt[v] <= x) {
        return t[v];
    }
    int m = (l + r) / 2;
    if (cnt[v * 2 + 1] >= x) {
        return get_sum(v * 2 + 1, l, m, x);
    } else {
        return t[v * 2 + 1] + get_sum(v * 2 + 2, m, r, x - cnt[v * 2 + 1]);
    }
}

long long get_sum(int l, int r) {
    if (r < l) {
        return (long long) 0;
    }
    return get_sum(0, 0, M, r + 1) - get_sum(0, 0, M, l);
}

long long getx(int i) {
    return get_sum(0, i) - get_sum(cnt[0] - i, cnt[0] - 1);
}

long long get_prog(int v, int l, int r, int l1, int r1) {
    if (l1 >= r || l >= r1) {
        return (long long) 0;
    }
    if (l1 <= l && r <= r1) {
        long long res = d[v] + t[v] * 1ll * tmp;
        tmp += cnt[v];
        return res;
    }
    int m = (l + r) / 2;
    long long R = get_prog(v * 2 + 2, m, r, l1, r1);
    long long L = get_prog(v * 2 + 1, l, m, l1, r1);
    return L + R;
}

long long get_progg(int v, int l, int r, int l1, int r1) {
    if (l1 >= r || l >= r1) {
        return (long long) 0;
    }
    if (l1 <= l && r <= r1) {
        long long res = f[v] + t[v] * 1ll * tmp;
        tmp += cnt[v];
        return res;
    }
    int m = (l + r) / 2;
    long long L = get_progg(v * 2 + 1, l, m, l1, r1);
    long long R = get_progg(v * 2 + 2, m, r, l1, r1);
    return L + R;
}

long long progress(int l, int r) {
    if (r < l) {
        return (long long) 0;
    }
    long long res = 0;
    res += get_sum(0, l - 1) * 1ll * (r - l + 1);
    //cout << res << endl;
    tmp = 0;
    res += get_prog(0, 0, M, id(l), id(r) + 1);
    //cout << res << endl;
    res -= get_sum(cnt[0] - l + 1, cnt[0] - 1) * 1ll * (r - l + 1);
    //cout << res << endl;
    tmp = 0;
    res -= get_progg(0, 0, M, id(cnt[0] - r), id(cnt[0] - l) + 1);
    //cout << res << endl;
    return res;
}

void solve() {
    long long ans = sum;
    //for (int i = 0; i < cnt[0]; i++) {
    //    cout << getx(i) << " ";
    //} cout << endl;
    {
        int l = -1, r = cnt[0] / 2;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (getx(m) >= 0) {
                l = m;
            } else {
                r = m;
            }
        }
        ans -= progress(0, l);
        //cout << progress(0, l) << " " << 0 << " " << l << endl;
    }
    {
        int l = cnt[0] / 2 - 1, r = cnt[0];
        while (l + 1 < r) {
            int m = (l + r) / 2;
            if (getx(m) >= 0) {
                r = m;
            } else {
                l = m;
            }
        }
        ans -= progress(r, cnt[0] - 1);
        //cout << progress(r, cnt[0] - 1) << " " << r << " " << n - 1 << endl;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        z.push_back(s[i]);
    }
    for (int i = 0; i < q; i++) {
        cin >> type[i] >> a[i];
        z.push_back(a[i]);
    }
    sort(z.begin(), z.end());
    z.resize(unique(z.begin(), z.end()) - z.begin());
    M = (int) z.size();
    for (int i = 0; i < n; i++) {
        update(0, 0, M, lower_bound(z.begin(), z.end(), s[i]) - z.begin(), 1);
    }
    solve();
    for (int i = 0; i < q; i++) {
        update(0, 0, M, lower_bound(z.begin(), z.end(), a[i]) - z.begin(), type[i] % 2);
        solve();
    }
}