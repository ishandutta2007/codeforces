#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <deque>
#include <memory.h>
#include <assert.h>
#include <cstring>
#include <cmath>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

struct node {
    ll sum;
    bool ones;
    node() : sum(0), ones(false) {}
};

vector<node> t;

void build(int v, int tl, int tr, const vector<int>& a) {
    if (tl == tr) {
        t[v].sum = a[tl];
        if (t[v].sum == 1 || t[v].sum == 2) {
            t[v].ones = true;
        } else {
            t[v].ones = false;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
    t[v].ones = (t[v * 2].ones & t[v * 2 + 1].ones);
}

const int nmax = 1e6 + 100;

int cnt[nmax];

void update(int v, int tl, int tr, int l, int r) {
    if (t[v].ones) {
        return;
    }
    if (tl == tr) {
        t[v].sum = cnt[t[v].sum];
        if (t[v].sum == 1 || t[v].sum == 2) {
            t[v].ones = true;
        } else {
            t[v].ones = false;
        }
        return;
    }
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        update(v * 2, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    t[v].sum = t[v * 2].sum + t[v * 2 + 1].sum;
    t[v].ones = (t[v * 2].ones & t[v * 2 + 1].ones);
}

ll get(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) {
        return t[v].sum;
    }
    int tm = (tl + tr) >> 1;
    ll ans = 0;
    if (l <= tm) {
        ans += get(v * 2, tl, tm, l, min(r, tm));
    }
    if (r > tm) {
        ans += get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }
    return ans;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    t.resize(4 * n);
    build(1, 0, n - 1, a);

    for (int i = 1; i < nmax; ++i) {
        for (int j = i; j < nmax; j += i) {
            ++cnt[j];
        }
    }

    while (q--) {
        int type;
        int l, r;
        cin >> type >> l >> r;
        --l, --r;
        if (type == 2) {
            cout << get(1, 0, n - 1, l, r) << "\n";
        } else {
            update(1, 0, n - 1, l, r);
        }
    }

}