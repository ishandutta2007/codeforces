#include "bits/stdc++.h"

using namespace std;

const int N = 2e6;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> g(N), v(N), pos(N);
    int index = 0;
    map<int, int> a;
    auto add = [&] (int i, int x) {
        if (a.find(x) == a.end()) {
            v[index] = x;
            g[index] = index;
            a[x] = index++;
        }
        pos[i] = index++;
        g[pos[i]] = a[x];
    };
    function<int(int)> get = [&] (int v) {
        if (g[v] == v) {
            return v;
        }
        return g[v] = get(g[v]);
    };
    auto merge = [&] (int x, int y) {
        int i = a[x], j = a[y];
        a.erase(x);
        g[i] = j;
    };
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(i, x);
    }
    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int i, x;
            cin >> i >> x;
            i--;
            add(i, x);
        } else if (t == 2) {
            int i;
            cin >> i;
            i--;
            cout << v[get(pos[i])] << '\n';
        } else {
            int l, r;
            cin >> l >> r;
            while (1) {
                auto it = a.lower_bound(l);
                if (it == a.end() || (*it).first > r) {
                    break;
                }
                int x = (*it).first, j = (*it).second;
                if (abs(x - l) < abs(x - r)) {
                    if (a.find(l - 1) != a.end()) {
                        merge(x, l - 1);
                    } else {
                        a.erase(x);
                        v[j] = l - 1;
                        a[l - 1] = j;
                    }
                } else {
                    if (a.find(r + 1) != a.end()) {
                        merge(x, r + 1);
                    } else {
                        a.erase(x);
                        v[j] = r + 1;
                        a[r + 1] = j;
                    }
                }
            }
        }
        // vector<int> ans(n);
        // for (int i = 0; i < n; i++) {
        //     ans[i] = v[pos[i]];
        // }
        // debug(g, a, f, pos, v, ans);
    }
}