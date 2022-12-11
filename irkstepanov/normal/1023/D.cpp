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
typedef long double ld;
typedef pair<ld, ld> pld;

struct node {
    int promise;
    int val;
    node() : promise(-1), val(-1) {}
};

vector<node> t;

void push(int v) {
    if (t[v].promise == -1) {
        return;
    }
    int x = t[v].promise;
    t[v * 2].promise = x;
    t[v * 2].val = x;
    t[v * 2 + 1].promise = x;
    t[v * 2 + 1].val = x;
    t[v].promise = -1;
}

void assign(int v, int tl, int tr, int l, int r, int x) {
    if (tl == l && tr == r) {
        t[v].promise = x;
        t[v].val = x;
        return;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (l <= tm) {
        assign(v * 2, tl, tm, l, min(r, tm), x);
    }
    if (r > tm) {
        assign(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, x);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v].val;
    }
    push(v);
    int tm = (tl + tr) >> 1;
    if (pos <= tm) {
        return get(v * 2, tl, tm, pos);
    } else {
        return get(v * 2 + 1, tm + 1, tr, pos);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    bool lst = false;
    bool zero = false;
    for (int i = 0; i < n; ++i) {
        if (a[i] == q) {
            lst = true;
        }
        if (a[i] == 0) {
            zero = true;
        }
    }

    if (!lst && !zero) {
        cout << "NO\n";
        return 0;
    }

    vector<int> firstpos(q + 1, -1);
    vector<int> lastpos(q + 1, -1);
    for (int i = 0; i < n; ++i) {
        if (!a[i]) {
            continue;
        }
        int val = a[i];
        if (firstpos[val] == -1) {
            firstpos[val] = i;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (!a[i]) {
            continue;
        }
        int val = a[i];
        if (lastpos[val] == -1) {
            lastpos[val] = i;
        }
    }

    int z1 = -1, z2 = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && z1 == -1) {
            z1 = i;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        if (a[i] == 0 && z2 == -1) {
            z2 = i;
        }
    }

    t.resize(4 * n);
    assign(1, 0, n - 1, 0, n - 1, 1);
    for (int val = 2; val < q; ++val) {
        int a = firstpos[val];
        int b = lastpos[val];
        if (a == -1) {
            continue;
        }
        assign(1, 0, n - 1, a, b, val);
    }
    if (firstpos[q] == -1) {
        assign(1, 0, n - 1, z1, z1, q);
    } else {
        assign(1, 0, n - 1, firstpos[q], lastpos[q], q);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i] = get(1, 0, n - 1, i);
    }

    for (int i = 0; i < n; ++i) {
        if (a[i] != 0 && a[i] != ans[i]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}