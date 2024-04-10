#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;

vector<vector<int> > g;
ll ans = 0;
int k;

vector<int> dfs(int v, int p) {
    vector<int> sum(k + 1, 0);
    sum[0] = 1;
    for (int to : g[v]) {
        if (to == p) {
            continue;
        }
        vector<int> nx = dfs(to, v);
        for (int i = 0; i < k; ++i) {
            ans += ll(nx[i]) * sum[k - i - 1];
        }
        for (int i = 0; i < k; ++i) {
            sum[i + 1] += nx[i];
        }
    }
    return sum;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

    int n;
    cin >> n >> k;
    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, -1);
    cout << ans << "\n";

}