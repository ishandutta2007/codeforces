// Retired?
#include <bits/stdc++.h>
using namespace std;

namespace R = ranges;
auto ra(auto x, auto y) { return R::iota_view(x, y); }

using ll = long long;
using ull = long unsigned long;
using ld = double long;

struct union_find {
    vector<int> p;
    union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
    bool operator() (int x, int y) { return e(x) == e(y); }
    int e(int x) {
        if (p[x] == x) return x;
        return p[x] = e(p[x]);
    }
    bool join(int x, int y) {
        x = e(x), y = e(y);
        if (x == y) return false;
        p[x] = y;
        return true;
    }
};

vector<vector<int>> gnc(const vector<int>& a) {
    int n = a.size();
    vector<vector<int>> nc(32);
    for (int j : ra(0, n)) {
        nc[countr_zero((unsigned)a[j])].push_back(j);
    }
    return nc;
}

vector<int> two_op(vector<int> a) {
    int n = a.size();
    auto nc = gnc(a);
    int bits = 31;
    while (nc[bits].empty()) {
        bits--;
    }

    a[nc[bits][0]]--;
    a[nc[bits][1]]++;
    return a;
}

bool conn(vector<int> a) {
    int n = a.size();
    auto nc = gnc(a);
    union_find uf(n);
    int joins = 0;
    for (int i : ra(0, 30)) {
        int last = -1;
        for (int j : ra(0, n)) {
            if (a[j] & (1 << i)) {
                if (last != -1) {
                    joins += uf.join(last, j);
                }
                last = j;
            }
        }
    }
    return joins == n-1;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& x : a) cin >> x;
        auto a0 = a;

        // always needs to be done
        for (int& x : a) {
            if (x == 0) {
                x = 1;
            }
        }

        if (!conn(a)) {
            for (int i : ra(0, n)) {
                auto b = a;
                if (b[i] > 1) {
                    b[i] = a[i] - 1;
                    if (conn(b)) {
                        a = b;
                        break;
                    }
                }

                b[i] = a[i] + 1;
                if (conn(b)) {
                    a = b;
                    break;
                }
            }
        }

        if (!conn(a)) {
            a = two_op(a);
        }

        // print
        int z = 0;
        for (int i : ra(0, n)) {
            z += abs(a[i] - a0[i]);
        }
        cout << z << '\n';
        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
    }   
}