#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

vector<vector<int> > g;
vector<int> tin;
vector<int> color;

int cycle = -1;

void dfs(int v, int t) {
    tin[v] = t;
    color[v] = 1;
    for (int to : g[v]) {
        if (color[to] == 1) {
            cycle = tin[v] - tin[to] + 1;
        } else if (color[to] == 0) {
            dfs(to, t + 1);
        }
    }
    color[v] = 2;
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
    cin >> n >> m;
    g.resize(n);
    tin.resize(n);
    color.assign(n, 0);

    while (m--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(v);
    }

    dfs(0, 0);
    assert(cycle != -1);

    int ans = 0;
    vector<int> vct;
    for (int d = 1; d <= cycle; ++d) {
        if (cycle % d) {
            continue;
        }
        vector<int> block(n, -1);
        queue<int> q;
        q.push(0);
        block[0] = 0;
        bool ok = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int to : g[v]) {
                if (block[to] == -1) {
                    block[to] = (block[v] + 1) % d;
                    q.push(to);
                } else if (block[to] != (block[v] + 1) % d) {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && d > ans) {
            ans = d;
            vct = {};
            for (int v = 0; v < n; ++v) {
                if (block[v] == 0) {
                    vct.pb(v);
                }
            }
        }
    }

    cout << ans << "\n";
    cout << sz(vct) << "\n";
    for (int x : vct) {
        cout << x + 1 << " ";
    }
    cout << "\n";

}