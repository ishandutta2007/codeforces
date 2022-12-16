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

int n, k;
int x, y;
int a[MAXN];
vector<int> adj[MAXN];
int par[MAXN];
vector<int> children[MAXN];

//int addeddist[MAXN];
int bigboy[MAXN];

void dfs(int curr) {
    for (int nxt : adj[curr]) {
        if (par[nxt] == -1) {
            par[nxt] = curr;
            children[curr].pb(nxt);
            dfs(nxt);
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> x >> y;
        x--; y--;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            a[i]--;
        }
        for (int i = 0; i < n; i++) adj[i].clear();
        for (int i = 0; i < n; i++) par[i] = -1;
        for (int i = 0; i < n; i++) children[i].clear();

        for (int i = 0; i < n-1; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        par[x] = -2;
        dfs(x); // root at x

        for (int i = 0; i < n; i++) {
            //addeddist[i] = -1;
            bigboy[i] = -1;
            
        }
        bigboy[x] = 0;
        bigboy[y] = 1;

        for (int i = 0; i < k; i++) {
            if (bigboy[a[i]] == -1) {
                // crawl up
                vector<int> seen;
                int curr = a[i];
                while (bigboy[curr] == -1) {
                    seen.pb(curr);
                    curr = par[curr];
                }
                for (int thing : seen) bigboy[thing] = bigboy[curr];
            }
        }

        int curr = y;
        int out = 0;
        while (curr != x) {
            bigboy[curr] = 2;
            curr = par[curr];
        }
        bigboy[x] = -1;

        for (int i = 0; i < n; i++) {
            //cout << bigboy[i] << endl;
            if (bigboy[i] == 0 || bigboy[i] == 1) out += 2;
            else if (bigboy[i] == 2) out++;
        }
        cout << out << '\n';

    }
}