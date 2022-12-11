 #include <bits/stdc++.h>
#include <string.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;
typedef pair<ll, int> pll;

vector<int> g;
vector<vector<int> > back;
vector<char> used;
vector<int> visited;

int dfs(int v)
{
    used[v] = true;
    visited.pb(v);
    if (used[g[v]]) {
        return g[v];
    }
    return dfs(g[v]);
}

vector<int> bad;

void back_dfs(int v)
{
    used[v] = true;
    if (back[v].empty()) {
        bad.pb(v);
    }
    for (int x : back[v]) {
        if (!used[x]) {
            back_dfs(x);
        }
    }
}

int main()
{

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    g.resize(n);
    back.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i];
        --g[i];
        back[g[i]].pb(i);
    }

    used.assign(n, false);
    vector<pii> ans;
    vector<int> vv, uu;
    for (int i = 0; i < n; ++i) {
        if (!used[i]) {
            int v = dfs(i); // vertex of cicle
            vv.pb(v);
            for (int x : visited) {
                used[x] = false;
            }
            visited.clear();
            back_dfs(v);
            for (int j = 0; j < sz(bad) - 1; ++j) {
                ans.pb(mp(v, bad[j]));
            }
            if (!bad.empty()) {
                uu.pb(bad.back());
            } else {
                uu.pb(-1);
            }
            bad.clear();
        }
    }

    if (sz(vv) == 1 && uu[0] == -1) {
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < sz(vv); ++i) {
        if (uu[(i + 1) % sz(vv)] == -1) {
            ans.pb(mp(vv[i], vv[(i + 1) % sz(vv)]));
        } else {
            ans.pb(mp(vv[i], uu[(i + 1) % sz(vv)]));
        }
    }

    cout << sz(ans) << "\n";
    for (pii& p : ans) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

}