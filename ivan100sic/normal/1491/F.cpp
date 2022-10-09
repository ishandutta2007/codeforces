// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int ask(vector<int> lhs, vector<int> rhs) {
    int n = lhs.size();
    int m = rhs.size();
    cout << "? " << n << ' ' << m << '\n';
    for (int i=0; i<n; i++) {
        cout << lhs[i] << " \n"[i == n-1];
    }

    for (int i=0; i<m; i++) {
        cout << rhs[i] << " \n"[i == m-1];
    }

    cout << flush;

    int x;
    cin >> x;
    return x;
}

vector<int> ra(int l, int r) {
    vector<int> a(r-l+1);
    iota(begin(a), end(a), l);
    return a;
}

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int drugi = 0;
        for (int x=2; x<=n; x++) {
            // x i svi
            if (ask(ra(1, x-1), {x})) {
                drugi = x;
                break;
            }
        }

        int l = 1, r = drugi-1, o = -1;
        while (l <= r) {
            int m = (l+r) / 2;
            if (ask(ra(m, drugi-1), {drugi})) {
                o = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        int prvi = o;
        vector<bool> jeste(n+1);
        jeste[prvi] = jeste[drugi] = true;
        for (int i=drugi+1; i<=n; i++) {
            if (ask({prvi}, {i})) {
                jeste[i] = true;
            }
        }

        cout << "! " << count(begin(jeste) + 1, end(jeste), false);
        for (int x=1; x<=n; x++) if (!jeste[x]) cout << ' ' << x;
        cout << '\n' << flush;
    }
}