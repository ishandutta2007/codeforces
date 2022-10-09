// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

class xorset {
    int c = 0;
    set<int> s;

public:
    bool contains(int x) {
        return s.contains(x ^ c);
    }
    
    void insert(int x) {
        s.insert(x ^ c);
    }

    auto size() {
        return s.size();
    }

    // call on greater
    bool bad(int root, const xorset& b) {
        for (int y : b.s) {
            if (contains(y ^ b.c ^ root)) {
                return true;
            }
        }
        return false;
    }

    // call on greater
    void merge(const xorset& b) {
        for (int y : b.s) {
            insert(y ^ b.c);
        }
    }

    void xor_all(int x) {
        c ^= x;
    }
};

int n;
int a[200005];
vector<int> e[200005];

int sol;

xorset dfs(int x, int p) {
    xorset tot;
    bool empty = false;

    for (int y : e[x]) {
        if (y == p) continue;
        auto yv = dfs(y, x);

        if (yv.contains(a[x])) {
            empty = true;
        }

        if (tot.size() < yv.size()) {
            swap(tot, yv);
        }

        if (tot.bad(a[x], yv)) {
            empty = true;
        }

        tot.merge(yv);
    }

    if (empty) {
        sol++;
        return {};
    }

    tot.insert(0);
    tot.xor_all(a[x]);
    
    // cerr << "node " << x << '\n';
    // for (int y : tot.elems()) {
    //     cerr << y << ' ';
    // }
    // cerr << '\n';
    
    return tot;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i : ra(0, n)) cin >> a[i];

    for (int i : ra(1, n)) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    dfs(0, 0);
    cout << sol << '\n';
}