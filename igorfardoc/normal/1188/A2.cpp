#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
vector<vector<pair<int, int>>> g;
map<pair<int, int>, ll> am;
vector<ll> need;

void add(int v, int u, ll val) {
    if(v > u) {
        swap(v, u);
    }
    am[{v, u}] += val;
    need[v] -= val;
    need[u] -= val;
}

bool cmp(const vi& a, const vi& b) {
    return a.size() > b.size();
}

void dfs(int v, int p, int w, vi& res) {
    if(g[v].size() == 1) {
        need[v] = w;
        res.push_back(v);
        return;
    }
    vvi here;
    for(auto& u1 : g[v]) {
        int u = u1.first;
        int where = u1.second;
        if(u == p) continue;
        vi here1;
        dfs(u, v, where, here1);
        here.push_back(here1);
    }
    int other;
    while(here.size() != 2) {
        int v1 = here[here.size() - 2][0];
        for(const auto& v2 : here[here.size() - 1]) {
            add(v1, v2, need[v2]);
            other = v2;
        }
        here.pop_back();
    }
    sort(here.begin(), here.end(), cmp);
    if(here[1].size() == 2) {
        int v1 = here[0][0];
        int v2 = here[1][1];
        add(v1, v2, need[v2]);
        here[1].pop_back();
    }
    if(here[0].size() == 2) {
        int v1 = here[1][0];
        int v2 = here[0][1];
        add(v1, v2, need[v2]);
        here[0].pop_back();
    }
    int v1 = here[0][0];
    int v2 = here[1][0];
    ll have = need[v1] + need[v2];
    add(v1, v2, (have - w) / 2);
    if(p == -1) {
        add(v1, other, need[v1]);
        add(v2, other, need[v2]);
    }
    res.push_back(v1);
    res.push_back(v2);
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
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int v, u, w;
        cin >> v >> u >> w;
        --v;
        --u;
        g[v].push_back({u, w});
        g[u].push_back({v, w});
    }
    need.resize(n);
    if(n == 2) {
        cout << "YES\n1\n1 2 " << g[0][0].second;
        return 0;
    }
    int start = -1;
    for(int i = 0; i < n; i++) {
        if(g[i].size() == 2) {
            cout << "NO";
            return 0;
        }
        if(g[i].size() != 1) {
            start = i;
        }
    }
    vi res;
    dfs(start, -1, 0, res);
    //cout << need[res[0]] << ' ' << need[res[1]] << endl;

    cout << "YES\n";
    vector<array<ll, 3>> ans;
    for(const auto& el : am) {
        if(el.second != 0) {
            ans.push_back({el.first.first, el.first.second, el.second});
        }
    }
    cout << ans.size() << '\n';
    for(const auto& el : ans) {
        cout << el[0] + 1 << ' ' << el[1] + 1 << ' ' << el[2] << '\n';
    }

}