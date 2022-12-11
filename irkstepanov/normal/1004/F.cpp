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
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

int x;

struct node {
    vector<int> last;
    vector<int> first;
    ll cnt;
    node() : cnt(0) {}
};

vector<node> t;
vector<int> a;

void unite(node& ans, node& left, node& right) {
    ans.cnt = left.cnt + right.cnt;
    int val = 0;
    ans.last = right.last;
    for (int pos : ans.last) {
        val |= a[pos];
    }
    for (int j = 0; j < sz(left.last); ++j) {
        int pos = left.last[j];
        if ((val | a[pos]) != val || j == sz(left.last) - 1) {
            ans.last.pb(pos);
            val |= a[pos];
        }
    }
    ans.first = left.first;
    val = 0;
    for (int pos : ans.first) {
        val |= a[pos];
    }
    for (int j = 0; j < sz(right.first); ++j) {
        int pos = right.first[j];
        if ((val | a[pos]) != val || j == sz(right.first) - 1) {
            ans.first.pb(pos);
            val |= a[pos];
        }
    }

    int init = 0;
    for (int i = 0; i < sz(left.last); ++i) {
        init |= a[left.last[i]];
        val = init;
        int j = 0;
        val |= a[right.first[0]];

        while (val < x) {
            ++j;
            if (j < sz(right.first)) { // 4 1 7 0 3 6 1 2 1 4
                val |= a[right.first[j]];
            } else {
                break;
            }
        }
        /*if (sz(left.last) == 2 && sz(right.first) == 2) {
            cout << i << " " << j << "\n";
        }*/
        if (j == sz(right.first)) {
            continue;
        }
        ll lf;
        if (i == sz(left.last) - 1) {
            lf = 1;
        } else {
            lf = left.last[i] - left.last[i + 1];
        }
        ans.cnt += lf * (right.first.back() - right.first[j] + 1);
    }
}

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v].last = {tl};
        t[v].first = {tl};
        if (a[tl] >= x) {
            t[v].cnt = 1;
        } else {
            t[v].cnt = 0;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    unite(t[v], t[v * 2], t[v * 2 + 1]);
}

void update(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        t[v].last = {tl};
        t[v].first = {tl};
        if (a[tl] >= x) {
            t[v].cnt = 1;
        } else {
            t[v].cnt = 0;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        update(v * 2, tl, tm, pos);
    } else {
        update(v * 2 + 1, tm + 1, tr, pos);
    }
    unite(t[v], t[v * 2], t[v * 2 + 1]);
}

void split(int v, int tl, int tr, int l, int r, vector<node>& ans) {
    if (tl == l && tr == r) {
        ans.pb(t[v]);
        return;
    }
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        split(v * 2, tl, tm, l, min(r, tm), ans);
    }
    if (r > tm) {
        split(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, ans);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    int q;
    cin >> q;
    cin >> x;

    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    t.resize(4 * n);
    build(1, 0, n - 1);



    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int pos, val;
            cin >> pos >> val;
            --pos;
            a[pos] = val;
            update(1, 0, n - 1, pos);
        } else {
            int l, r;
            cin >> l >> r;
            --l, --r;
            vector<node> vct;
            split(1, 0, n - 1, l, r, vct);
            node ans = vct[0];
            for (int i = 1; i < sz(vct); ++i) {
                node tmp;
                unite(tmp, ans, vct[i]);
                ans = tmp;
            }
            cout << ans.cnt << "\n";
        }
    }

}