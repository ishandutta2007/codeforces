#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

vector<vector<int> > g;
vector<ll> s;

const ll inf = 1e18;

ll sum = 0;
bool ok = true;

void dfs(int v) {
    for (int son : g[v]) {
        ll opt = inf;
        for (int to : g[son]) {
            opt = min(opt, s[to] - s[v]);
        }
        if (opt < 0) {
            ok = false;
            return;
        }
        if (opt == inf) {
            continue;
        }
        sum += opt;
        for (int to : g[son]) {
            sum += s[to] - s[v] - opt;
            dfs(to);
        }
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    for (int i = 1; i < n; ++i) {
        int p;
        cin >> p;
        --p;
        g[p].pb(i);
    }

    s.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    sum = s[0];
    dfs(0);

    if (!ok) {
        cout << "-1\n";
    } else {
        cout << sum << "\n";
    }

}