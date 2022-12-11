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

struct pt {
    ll x, y;
    int id;
    bool operator<(const pt& other) const {
        return x - y < other.x - other.y;
    }
};

int main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<pt> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
        p[i].id = i;
    }

    vector<ll> ans(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ans[u] -= min(p[u].x + p[v].y, p[u].y + p[v].x);
        ans[v] -= min(p[u].x + p[v].y, p[u].y + p[v].x);
    }
    sort(all(p));

    ll lf = 0, rg = 0;
    for (int i = 0; i < n; ++i) {
        rg += p[i].y;
    }

    for (int i = 0; i < n; ++i) {
        rg -= p[i].y;
        if (i) {
            lf += p[i - 1].x;
        }
        ans[p[i].id] += lf + rg + (p[i].x - p[i].y) * (n - i - 1) + p[i].y * (n - 1);
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}