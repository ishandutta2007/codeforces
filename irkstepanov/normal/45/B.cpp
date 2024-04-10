#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int rmax = 20;

vector<vector<int> > shifts;

int get(int v, int len) {
    for (int r = rmax - 1; r >= 0; --r) {
        if (len >= (1 << r)) {
            len -= (1 << r);
            v = shifts[r][v];
        }
    }
    return v;
}

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> g(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        --g[i];
    }

    shifts = vector<vector<int> >(rmax, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        shifts[0][i] = g[i];
    }
    for (int r = 0; r + 1 < rmax; ++r) {
        for (int v = 0; v < n; ++v) {
            int t = shifts[r][v];
            shifts[r + 1][v] = shifts[r][t];
        }
    }

    vector<pii> to(n);
    for (int i = 0; i < n; ++i) {
        to[i] = {i, 0};
    }

    int res = 0;
    vector<int> v(q);
    for (int i = 0; i < q; ++i) {
        cin >> v[i];
    }

    vector<bool> used(n, false);

    for (int i = 0; i < q; ++i) {
        int b;
        cin >> b;
        int a = (v[i] + res - 1) % n;
        vector<pii> vis;
        int init = b;
        res = 0;
        while (b) {
            if (!used[a]) {
                vis.pb({a, b});
                ++res;
                used[a] = true;
                to[a] = {get(a, b), b};
                a = g[a];
                --b;
                continue;
            }
            if (to[a].second >= b) {
                b = 0;
                break;
            }
            b -= to[a].second;
            a = to[a].first;
        }
        cout << res << "\n";
    }



}