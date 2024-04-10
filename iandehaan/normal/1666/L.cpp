#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef vector<int> vi;
typedef long long ll;

#define pb push_back
#define mp make_pair

#define MAXN 200'010

int n, m, s;
vi adj[MAXN];
int par[MAXN];
int imm[MAXN];
bool founddupe = false;
int d1, d2;

void dfs(int curr, int schild) {
    //cout << curr << ' ' << schild << endl;
    if (founddupe) return;
    for (int nxt : adj[curr]) {
        if (par[nxt] == -1) {
            if (curr != s) {
                par[nxt] = schild;
                imm[nxt] = curr;
                dfs(nxt, schild);
            }
            else {
                par[nxt] = nxt;
                imm[nxt] = curr;
                dfs(nxt, nxt);
            }
        } else {
            if (par[nxt] != -2 && par[nxt] != schild) {
                founddupe = true;
                d1 = nxt;
                d2 = curr;
                return;
            }
        }
        if (founddupe) return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    memset(par, -1, sizeof par);

    cin >> n >> m >> s;
    s--;
    rep(i, 0, m) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
    }

    par[s] = -2;
    dfs(s, -1);

    if (founddupe) {
        vi out1;
        int curr = d1;
        while (curr != s) {
            out1.pb(curr);
            curr = imm[curr];
        }
        out1.pb(s);

        vi out2;
        out2.pb(d1);
        curr = d2;
        while (curr != s) {
            out2.pb(curr);
            curr = imm[curr];
        }
        out2.pb(s);
        reverse(all(out1));
        reverse(all(out2));
        cout << "Possible" << endl;
        cout << sz(out1) << endl;
        for (int x : out1) cout << x+1 << ' ';
        cout << endl;
        cout << sz(out2) << endl;
        for (int x : out2) cout << x+1 << ' ';
        cout << endl;
    } else {
        cout << "Impossible" << endl;
    }
}