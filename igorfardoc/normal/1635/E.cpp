#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
int n, m;
vvi g1;
vector<int> tp;
bool ok = true;
vector<char> ans1;
vi ans2;
vvi g;
vi c;
vi order;
vector<bool> used;
void dfs1(int v, int here) {
    tp[v] = here;
    for(int u : g1[v]) {
        if(here == tp[u]) {
            ok = false;
            return;
        }
        if(tp[u] != -1) continue;
        tp[u] = 1 - here;
        dfs1(u, 1 - here);
    }
}

void dfs2(int v) {
    c[v] = 0;
    for(int u : g[v]) {
        if(c[u] == 0) {
            ok = false;
            return;
        }
        if(c[u] == -1) {
            dfs2(u);
        }
    }
    c[v] = 1;
}

void dfs3(int v) {
    used[v] = true;
    for(int u : g[v]) {
        if(!used[u]) dfs3(u);
    }
    order.push_back(v);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifdef _FILE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    g1.resize(n);
    g.resize(n);
    tp.assign(n, -1);
    ans1.resize(n);
    ans2.resize(n);
    vector<array<int, 3>> all(m);
    for(int i = 0; i < m; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        --x;
        --y;
        all[i] = {type, x, y};
        g1[x].push_back(y);
        g1[y].push_back(x);
    }
    for(int i = 0; i < n; i++) {
        if(tp[i] == -1) {
            dfs1(i, 0);
        }
    }
    if(!ok) {
        cout << "NO";
        return 0;
    }
    for(int i = 0; i < n; i++) {
        if(tp[i] == 0) {
            ans1[i] = 'R';
        } else {
            ans1[i] = 'L';
        }
    }
    for(int i = 0; i < m; i++) {
        int v = all[i][1];
        int u = all[i][2];
        int type = all[i][0];
        if(tp[v] == 1) swap(v, u);
        if(type == 1) {
            g[u].push_back(v);
        } else {
            g[v].push_back(u);
        }
    }
    c.assign(n, -1);
    for(int i = 0; i < n; i++) {
        if(c[i] == -1) {
            dfs2(i);
        }
    }
    if(!ok) {
        cout << "NO";
        return 0;
    }
    used.assign(n, false);
    for(int i = 0; i < n; i++) {
        if(!used[i]) dfs3(i);
    }
    int now = 0;
    for(int i = order.size() - 1; i >= 0; i--) {
        ans2[order[i]] = now++;
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) { 
        cout << ans1[i] << ' ' << ans2[i] << '\n';
    }
}