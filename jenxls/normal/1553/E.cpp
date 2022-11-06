#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
#include <cassert>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdio>
#include <bitset>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;

#define pb push_back
#define F first
#define S second
#define _sz(x) ((int)x.size())

int T;

const int N = 3e5 + 20;
int n, m, a[N];
int cnt[N];

bool vis[N];
vector <int> g[N];

void dfs (int v) {
    vis[v] = 1;
    for (int u : g[v])
        if (!vis[u]) dfs(u);
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);

    cin >> T;
    
    while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> a[i], a[i]--;

        for (int i = 0; i < n; i++) cnt[i] = 0;

        for (int i = 0; i < n; i++)
            cnt[(i - a[i] + n) % n]++;

        vector <int> vec;

        for (int i = 0; i < n; i++)
            if (cnt[i] >= n - 2 * m) vec.pb(i);

        vector <int> ans;

        for (int k: vec) {
            for (int i = 0; i < n; i++) g[i].clear(), vis[i] = 0;

            int tot = 0;
            for (int i = 0; i < n; i++)
                if ((a[i] + k) % n != i) g[i].pb((a[i] + k) % n), tot++;

            int num = 0;
            for (int i = 0; i < n; i++) {
                if (_sz(g[i]) && !vis[i]) dfs(i), num++;
            }

            if (tot - num <= m) ans.pb(k);
        }

        sort(ans.begin(), ans.end());

        cout << _sz(ans) << ' ';
        for (int k: ans) cout << k << ' ';
        cout << '\n';
    }
}