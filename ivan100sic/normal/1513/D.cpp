// Retired?
#include <bits/stdc++.h>
using namespace std;

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

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n, p;
        cin >> n >> p;
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }

        vector<int> b(n);
        iota(begin(b), end(b), 0);
        sort(begin(b), end(b), [&](int i, int j) { return a[i] < a[j]; });
        
        union_find uf(n);

        int comps = n;
        ll sol = 0;
        for (int i : b) {
            if (a[i] >= p) {
                break;
            }

            int j = i + 1;
            while (j < n && a[j] % a[i] == 0 && !uf(i, j)) {
                sol += a[i];
                comps--;
                uf.join(i, j);
                j++;
            }

            j = i - 1;
            while (j >= 0 && a[j] % a[i] == 0 && !uf(i, j)) {
                sol += a[i];
                comps--;
                uf.join(i, j);
                j--;
            }
        }

        sol += (comps - 1ll) * p;
        cout << sol << '\n';
    }
}