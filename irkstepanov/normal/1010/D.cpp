#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <vector>
#include <cstring>
#include <bitset>
#include <random>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
//typedef __int128 ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

vector<string> op;
vector<vector<int> > g;
vector<int> def;

void dfs(int v) {
    if (g[v].empty()) {
        return;
    }
    for (int to : g[v]) {
        dfs(to);
    }
    if (op[v] == "NOT") {
        def[v] = 1 - def[g[v][0]];
    } else {
        int a = def[g[v][0]], b = def[g[v][1]];
        if (op[v] == "AND") {
            def[v] = (a & b);
        } else if (op[v] == "OR") {
            def[v] = (a | b);
        } else {
            def[v] = (a ^ b);
            assert(op[v] == "XOR");
        }
    }
}

vector<vector<int> > ans;

void dfs2(int v) {
    if (g[v].empty()) {
        return;
    }
    if (op[v] == "NOT") {
        int to = g[v][0];
        for (int d = 0; d < 2; ++d) {
            ans[to][d] = ans[v][1 - d];
        }
        dfs2(to);
        return;
    }
    int a[2] = {g[v][0], g[v][1]};
    for (int i = 0; i < 2; ++i) {
        int y = def[a[1 - i]];
        for (int d = 0; d < 2; ++d) {
            if (op[v] == "AND") {
                ans[a[i]][d] = ans[v][d & y];
            } else if (op[v] == "OR") {
                ans[a[i]][d] = ans[v][d | y];
            } else {
                ans[a[i]][d] = ans[v][d ^ y];
                assert(op[v] == "XOR");
            }
        }
    }
    for (int i = 0; i < 2; ++i) {
        dfs2(a[i]);
    }
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    op.resize(n);
    g.resize(n);
    def.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> op[i];
        if (op[i] == "IN") {
            cin >> def[i];
        } else {
            int t = 2;
            if (op[i] == "NOT") {
                t = 1;
            }
            while (t--) {
                int to;
                cin >> to;
                --to;
                g[i].pb(to);
            }
        }
    }

    dfs(0);

    ans = vector<vector<int> >(n, vector<int>(2));
    for (int d = 0; d < 2; ++d) {
        ans[0][d] = d;
    }

    dfs2(0);

    for (int i = 0; i < n; ++i) {
        if (g[i].empty()) {
            cout << ans[i][1 - def[i]];
        }
    }
    cout << "\n";

}