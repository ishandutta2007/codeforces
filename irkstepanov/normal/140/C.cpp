#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int nmax = 100500;

int t[4 * nmax];

void build(int v, int tl, int tr, const vector<int>& a) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

void update(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        t[v] = val;
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos, val);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos, val);
    }
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr) {
    if (tl == tr) {
        return tl;
    }
    int tm = (tl + tr) >> 1;
    if (t[v] == t[v * 2 + 1]) {
        return get(v * 2 + 1, tm + 1, tr);
    } else {
        return get(v * 2, tl, tm);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> sorted;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sorted = a;
    sort(all(sorted));
    sorted.resize(unique(all(sorted)) - sorted.begin());

    int N = sz(sorted);
    vector<int> cnt(N);
    for (int i = 0; i < n; ++i) {
        int pos = lower_bound(all(sorted), a[i]) - sorted.begin();
        ++cnt[pos];
    }

    n = N;
    build(1, 0, n - 1, cnt);

    vector<vector<int> > ans;

    while (true) {
        vector<int> r;
        vector<pii> tt;
        for (int i = 0; i < 3; ++i) {
            int pos = get(1, 0, n - 1);
            if (cnt[pos] == 0) {
                break;
            }
            r.pb(sorted[pos]);
            tt.pb({pos, cnt[pos] - 1});
            update(1, 0, n - 1, pos, 0);
            cnt[pos] = 0;
        }
        if (sz(r) != 3) {
            break;
        }
        ans.pb(r);
        for (int i = 0; i < 3; ++i) {
            update(1, 0, n - 1, tt[i].first, tt[i].second);
            cnt[tt[i].first] = tt[i].second;
        }
    }

    cout << sz(ans) << "\n";
    for (int i = 0; i < sz(ans); ++i) {
        sort(all(ans[i]));
        reverse(all(ans[i]));
        for (int j = 0; j < 3; ++j) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }

}