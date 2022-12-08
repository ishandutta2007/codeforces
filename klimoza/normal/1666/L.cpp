#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <cmath>
#include <map>
#include <random>
#include <chrono>
#include <fstream>
#include <array>
#include <iomanip>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <sstream> 
#include <utility>
#include <functional>
#include <bitset>
#include <cassert>

using namespace std;
using ll = long long;
using ld = long double;

// #define int long long

#define pii pair<int, int>
#define vi vector<int>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define mp make_pair

const ld eps = 1e-8;
// const ll mod = 998244353;
const ll mod = 1e9 + 7;
const int MAXN = 3e5;
const int inf0 = 1e9 + 10;
const ll inf = 2e18 + 10;

void solve();

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#ifdef DEBUG
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
#endif
    cout << fixed;
    cout.precision(15);
    solve();
    return 0;
}

const int N = 2e5 + 2;
vector<int> g[N];
int p[N];
int used[N];
int c[N];

int s;
bool fl = false;
vector<int> ans1, ans2;

void dfs(int v, int col = -1, int par = -1) {
    p[v] = par;
    c[v] = col;
    used[v] = 1;
    for(int u : g[v]) {
        if(fl && used[u]) return;
        if(used[u] == 1) continue;
        if(used[u] == 2) {
            if(fl) continue;
            if(col == c[u]) continue;
            ans1 = vector<int>{u};
            int vertex = v;
            while(vertex != s) {
                ans1.push_back(vertex);
                vertex = p[vertex];
            }
            ans1.push_back(s);
            reverse(all(ans1));
            vertex = u;
            while(vertex != s) {
                ans2.push_back(vertex);
                vertex = p[vertex];
            }
            ans2.push_back(s);
            reverse(all(ans2));
            fl = true;
        } else {
            if(col == -1)
                dfs(u, u, v);
            else
                dfs(u, col, v);
        }
    }
    used[v] = 2;
}

void solve() {
    fill(used, used + N, 0);
    fill(c, c + N, -1);
    int n, m;
    cin >> n >> m >> s;
    s--;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].push_back(v);
    }
    dfs(s);
    if(!fl)
        cout << "Impossible\n";
    else {
        cout << "Possible\n";
        cout << ans1.size() << endl;
        for(int v : ans1) {
            cout << v + 1 << " ";
        }
        cout << endl;
        cout << ans2.size() << endl;
        for(int v : ans2) {
            cout << v + 1 << " ";
        }
        cout << endl;
    }
}