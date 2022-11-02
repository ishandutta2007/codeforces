#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

mt19937_64 rnd(time(0));

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define int ll

const int N = 1e5 + 50;

int t[4 * N];

int get(int v, int tl, int tr, int l, int r) {
    if (l > tr || r < tl || l > r) return 1e9;
    if (tl >= l && tr <= r) return t[v];
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
}

void update(int v, int tl, int tr, int pos, int x) {
    if (tl == tr) {
        t[v] = x;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(2 * v, tl, tm, pos, x);
    } else {
        update(2 * v + 1, tm + 1, tr, pos, x);
    }
    t[v] = min(t[2 * v], t[2 * v + 1]);
}

signed main() {
    int n;
    cin >> n;
    int a[n];
    for (auto &i : a) cin >> i;
    int ans[n + 10];
    memset(ans, 0, sizeof(ans));
    for (auto &i : a) {
        if (i > 1) ans[1] = 1;
    }
    memset(t, -1, sizeof(t));
    for (int i = 0; i < n; ++i) {
        if (i > 0 && a[i] > 1 &&
            get(1, 1, n + 10, 1, a[i] - 1) > get(1, 1, n + 10, a[i], a[i]))
            ans[a[i]] = 1;
        update(1, 1, n + 10, a[i], i);
    }
    for (int i = 2; i <= n + 3; ++i) {
        if (get(1, 1, n + 10, 1, i - 1) > get(1, 1, n + 10, i, i)) ans[i] = 1;
    }

    int ok = 1;
    for (int i = 1; i < n + 10; ++i) {
        if (ans[i] != 1) break;
        ok = i + 1;
    }
    cout << ok << endl;
    return 0;
}