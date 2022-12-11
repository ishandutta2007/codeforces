#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<char> used;
vector<int> path;

void dfs(int v)
{
    used[v] = true;
    path.pb(v);
    for (int to : g[v]) {
        if (!used[to]) {
            dfs(to);
            path.pb(v);
        }
    }
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    g.resize(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    used.assign(n, false);
    dfs(0);

    int len = (2 * n + k - 1) / k;
    vector<int> v;
    int op = 0;
    for (int i = 0; i < sz(path); ++i) {
        v.pb(path[i]);
        if (sz(v) == len) {
            cout << sz(v) << " ";
            for (int x : v) {
                cout << x + 1 << " ";
            }
            cout << "\n";
            ++op;
            v.clear();
        }
    }
    if (!v.empty()) {
        cout << sz(v) << " ";
        for (int x : v) {
            cout << x + 1 << " ";
        }
        cout << "\n";
        ++op;
        v.clear();
    }

    while (op < k) {
        cout << "1 1\n";
        ++op;
    }

}