// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct fat_union_find {
    vector<vector<int>> a;
    vector<int> b;
    set<int> r;

    fat_union_find(int n) : a(n), b(n) {
        for (int i=0; i<n; i++) {
            a[i] = {i};
            b[i] = i;
            r.emplace_hint(r.end(), i);
        }
    }

    void join(int x, int y) {
        x = b[x];
        y = b[y];
        if (x == y) return;
        if (a[x].size() > a[y].size()) swap(x, y);
        a[y].insert(a[y].end(), begin(a[x]), end(a[x]));
        for (int z : a[x]) b[z] = y;
        a[x].clear();
        r.erase(x);
    }
};

int find_not(set<int>& s, int x) {
    return *find_if(begin(s), end(s), [&](int v) { return v != x; });
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    fat_union_find le(n), re(n);

    for (int i=0; i<m1; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        le.join(x, y);
    }

    for (int i=0; i<m2; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        re.join(x, y);
    }

    if (le.r.size() > re.r.size()) swap(le, re);

    cout << le.r.size() - 1 << '\n';

    while (le.r.size() > 1) {
        auto y = re.a[find_not(re.r, re.b[0])][0];
        auto z = le.a[find_not(le.r, le.b[0])][0];

        int p = -1, q = -1;

        if (le.b[y] != le.b[0]) {
            p = 0, q = y;
        } else if (re.b[z] != re.b[0]) {
            p = 0, q = z;
        } else {
            p = y, q = z;
        }

        le.join(p, q);
        re.join(p, q);
        cout << p+1 << ' ' << q+1 << '\n';
    }
}