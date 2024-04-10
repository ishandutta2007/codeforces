#include<bits/stdc++.h>
 
using namespace std;

const int N = 2e5 + 22, M = 1e6 + 22;
long long t[4 * N];
int d[4 * N];

void push(int v, int l, int r) {
    t[v] += (r - l) * 1ll * d[v];
    if (l + 1 != r) {
        d[v * 2 + 1] += d[v];
        d[v * 2 + 2] += d[v];
    }
    d[v] = 0;
}

void update(int v, int l, int r, int l1, int r1, int x) {
    push(v, l, r);
    if (l1 >= r || l >= r1) {
        return;
    }
    if (l1 <= l && r <= r1) {
        d[v] += x;
        push(v, l, r);
        return;
    }
    int m = (l + r) / 2;
    update(v * 2 + 1, l, m, l1, r1, x);
    update(v * 2 + 2, m, r, l1, r1, x);
    t[v] = t[v * 2 + 1] + t[v * 2 + 2];
}

long long get(int v, int l, int r, int l1, int r1) {
    push(v, l, r);
    if (l1 >= r || l >= r1) {
        return 0ll;
    }
    if (l1 <= l && r <= r1) {
        return t[v];
    }
    int m = (l + r) / 2;
    return get(v * 2 + 1, l, m, l1, r1) + get(v * 2 + 2, m, r, l1, r1);
}

int n, q, a[N], tmp[N];
long long ans[M];
pair<int, int> g[N];
vector<pair<int, int>> qu[N];
vector<int> z;
set<pair<int, int>> st, need;

void upd(int x, int t) {
    int pos = tmp[x];
    if (g[x].first != -1 && g[x].first <= pos) {
        if (t == 1) {
            need.insert({g[x].first, min(pos, g[x].second)});
        } else {
            need.erase({g[x].first, min(pos, g[x].second)});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int rev = 0, cnt = 0;
    for (int i = 0; i + 1 < n; i++) {
        if (a[i] > a[i + 1]) {
            cnt++;
        }
    }
    if (cnt > n / 2) {
        rev = 1;
    }
    if (rev) {
        reverse(a, a + n);
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (rev) {
            swap(l, r);
            l = n - l - 1;
            r = n - r - 1;
        }
        qu[r].push_back({l, i});
    }
    for (int i = 1; i <= n; i++) {
        g[i] = {-1, -1};
        tmp[i] = -1;
    }
    for (int r = 0; r < n; r++) {
        g[a[r]] = {r, r};
        while ((int) z.size() && z.back() < a[r]) {
            int x = z.back();
            upd(x, -1);
            g[a[r]].first = g[x].first;
            g[x] = {-1, -1};
            z.pop_back();
        }
        z.push_back(a[r]);
        upd(a[r], 1);
        for (auto [x, i] : st) {
            if (x * 1ll * a[r] > n) {
                break;
            }
            int y = x * a[r];
            upd(y, -1);
            tmp[y] = max(tmp[y], i);
            upd(y, 1);
        }
        st.insert({a[r], r});
        assert(need.size() <= 50);
        for (auto [cl, cr] : need) {
            update(0, 0, n, cl, cr + 1, 1);
        }
        for (auto [l, i] : qu[r]) {
            ans[i] = get(0, 0, n, l, r + 1);
        }
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << '\n';
    }
}