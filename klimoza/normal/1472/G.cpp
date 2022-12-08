//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const ld eps = 1e-8;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
// const ll mod = 998244353;

void solve();
void scan();

signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout.precision(15);
    solve();
    return 0;
}

const int N = 2e5 + 2;

vector<int> g[N];
bool used[N];
int d[N];

void bfs(int s) {
    queue<int> q;
    q.push(s);
    used[s] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : g[v]) {
            if (used[u])
                continue;
            d[u] = d[v] + 1;
            used[u] = true;
            q.push(u);
        }
    }
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            g[i].clear();
            d[i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;
            g[a].push_back(b);
        }
        fill(used, used + n, false);
        bfs(0);
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++)
            a[i] = mp(d[i], i);
        vector<int> ans(n, inf0);
        sort(rall(a));
        for (auto u : a) {
            ans[u.second] = u.first;
            for (int v : g[u.second]) {
                if (d[v] > u.first)
                    ans[u.second] = min(ans[u.second], ans[v]);
                else
                    ans[u.second] = min(ans[u.second], d[v]);
            }
        }
        for (int i : ans)
            cout << i << " ";
        cout << endl;
    }
    return;
}