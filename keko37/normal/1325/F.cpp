#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
typedef pair <int, int> pi;

const int MAXN = 100005;

int n, m, lim, d, boja, cik;
int col[MAXN], dist[MAXN];
vector <int> v[MAXN], vis, is;
unordered_set <int> st;

void dfs (int x) {
    col[x] = boja;
    dist[x] = d++;
    vis.push_back(x);
    for (auto sus : v[x]) {
        if (col[sus] == 0) {
            dfs(sus);
            return;
        }
    }
    int mn = dist[x], ind = x;
    for (auto sus : v[x]) {
        if (col[sus] == col[x]) {
            if (dist[sus] < mn) {
                mn = dist[sus];
                ind = sus;
            }
        }
    }
    if (dist[x] - dist[ind] + 1 >= lim) {
        cik = 1;
        cout << 2 << endl;
        cout << dist[x] - dist[ind] + 1 << endl;
        for (int i = 0; i < vis.size(); i++) {
            if (dist[vis[i]] >= dist[ind]) cout << vis[i] << " ";
        }
    } else {
        is.push_back(x);
        for (int i = 0; i < vis.size(); i++) {
            if (dist[vis[i]] < dist[ind]) col[vis[i]] = 0; else st.erase(vis[i]);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    lim = ceil(sqrt(n));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 1; i <= lim; i++) {
        int x = *st.begin();
        vis.clear();
        boja++;
        dfs(x);
        if (cik) return 0;
    }
    cout << 1 << endl;
    for (auto x : is) cout << x << " ";
    return 0;
}