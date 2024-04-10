#include <bits/stdc++.h>

using namespace std;

map<int, int> uf, val;
map<int, vector<int> > cts;

void make(int a) {
    if (uf.find(a) == uf.end()) {
        uf[a] = a;
        cts[a].push_back(a);
        val[a] = 0;
    }
}

int main() {
    cin.sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    int last = 0;
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x, l ^= last, r ^= last, x ^= last;
            if (l > r) swap(l, r);
            ++r, make(l), make(r);
            if (uf[l] == uf[r]) continue;
            int v = val[l] ^ val[r] ^ x;
            l = uf[l];
            r = uf[r];
            if (cts[l].size() > cts[r].size()) swap(l, r);
            for (int a : cts[l]) {
                uf[a] = r, val[a] ^= v;
                cts[r].push_back(a);
            }
            cts.erase(l);
        } else {
            int l, r;
            cin >> l >> r, l ^= last, r ^= last;
            if (l > r) swap(l, r);
            ++r, make(l), make(r);
            if (uf[l] != uf[r]) {
                cout << -1 << '\n';
                last = 1;
            } else {
                cout << (val[l] ^ val[r]) << '\n';
                last = val[l] ^ val[r];
            }
        }
    }
}