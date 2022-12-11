#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

vector<ll> disc;
const ll inf = 1e18;

struct edge {
    int to;
    ll cost;
};
vector<vector<edge> > g;
bool ok = true;

void dfs(int v) {
    for (edge& e : g[v]) {
        dfs(e.to);
        if (!ok) {
            return;
        }
        if (disc[e.to] > 0) {
            disc[v] += disc[e.to];
            disc[e.to] = 0;
        }
    }
    for (edge& e : g[v]) {
        if (disc[e.to] < 0) {
            ll d = -disc[e.to];
            if (e.cost >= (disc[v] + inf + d - 1) / d) {
                ok = false;
                break;
            }
            disc[v] -= d * e.cost;
        }
    }
    if (v == 0 && disc[v] < 0) {
        ok = false;
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n;

    disc.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> disc[i];
    }
    for (int i = 0; i < n; ++i) {
        ll val;
        cin >> val;
        disc[i] -= val;
    }

    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        ll cost;
        cin >> cost;
        g[p].pb({i, cost});
    }

    ok = true;
    dfs(0);

    cout << (ok ? "YES\n": "NO\n");

}