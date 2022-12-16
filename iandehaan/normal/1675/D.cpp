#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

#define MAXN 200'010

int n;
vector<vector<int>> out;
vector<int> adj[MAXN];

void dfs(int curr, bool nw) {
    if (nw) {
        vector<int> mything;
        mything.pb(curr);
        out.pb(mything);
    } else {
        out[sz(out)-1].pb(curr);
    }

    for (int i = 0; i < sz(adj[curr]); i++) {
        if (i == 0) {
            dfs(adj[curr][i], false);
        } else {
            dfs(adj[curr][i], true);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        out.clear();
        cin >> n;
        int root;
        for (int i = 0; i < n; i++) adj[i].clear();
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            p--;
            if (p == i) {
                root = i;
                continue;
            }
            //adj[i].pb(p);
            adj[p].pb(i);
        }
        dfs(root, true);

        cout << sz(out) << '\n';
        for (vector<int>& blah : out) {
            cout << sz(blah) << '\n';
            for (int x : blah) cout << x+1 << ' ';
            cout << '\n';
        }
        cout << '\n';
    }
}