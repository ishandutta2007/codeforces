// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n;
vector<int> e[1005], q;
int p[1005];

int ask(int k) {
    cout << "? " << k;
    for (int i=0; i<k; i++) {
        cout << ' ' << q[i];
    }
    cout << '\n' << flush;
    int z;
    cin >> z;
    return z;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n;
    for (int i=1; i<n; i++) {
        int u, v;
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    q = {1};
    int qs = 0;
    p[1] = 1;
    while (qs != (int)q.size()) {
        int x = q[qs++];
        for (int y : e[x]) {
            if (p[y] == 0) {
                p[y] = x;
                q.push_back(y);
            }
        }
    }

    int tgt = ask(n);

    int l = 2, r = n-1, o = n;
    while (l <= r) {
        int m = (l+r) / 2;
        if (ask(m) == tgt) {
            o = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }

    cout << "! " << q[o-1] << ' ' << p[q[o-1]] << '\n' << flush;
}