#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

vector<vector<int> > g;
int cnt[2];

void dfs(int v, int p, int c) {
    ++cnt[c];
    for (int to : g[v]) {
        if (to != p) {
            dfs(to, v, c ^ 1);
        }
    }
}

int main() {

    //ifstream cin("input.txt");
    //freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    cin >> n;
    g.resize(n);
    cnt[0] = cnt[1] = 0;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    dfs(0, 0, 0);

    ll ans = ll(cnt[0]) * ll(cnt[1]) - ll(n - 1);
    cout << ans << "\n";

}