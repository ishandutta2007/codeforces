#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

int q1(int v) {
    ++v;
    cout << "d " << v << endl;
    int res;
    cin >> res;
    return res;
}

int q2(int v) {
    ++v;
    cout << "s " << v << endl;
    int res;
    cin >> res;
    --res;
    return res;
}

void ans(int v) {
    cout << "! " << v + 1 << endl;
}


int n;
vvi g;
int d;
vi sz;
vi sp;
vi dst;

void dfs(int v, int p, int dnow=0) {
    dst[v] = dnow;
    if(d == dnow) {
        sz[v] = 1;
        return;
    }
    sz[v] = 0;
    for(int u : g[v]) {
        if(u == p) continue;
        dfs(u, v, dnow + 1);
        sz[v] += sz[u];
    }
    for(int u : g[v]) {
        if(u == p) continue;
        if(sz[u] * 2 > sz[v]) {
            sp[v] = u;
            break;
        }
    }
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
    cin >> n;
    g.resize(n);
    sz.assign(n, 0);
    sp.assign(n, -1);
    dst.resize(n);
    for(int i = 0; i < n - 1; i++) {
        int v, u;
        cin >> v >> u;
        --v;
        --u;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    d = q1(0);
    dfs(0, -1);
    if(d == 0) {
        ans(0);
        return 0;
    }
    vi st;
    int curr = 0;
    while(true) {
        if(dst[curr] == d) {
            ans(curr);
            return 0;
        }
        vi st;
        st.push_back(curr);
        while(sp[st[st.size() - 1]] != -1) {
            st.push_back(sp[st[st.size() - 1]]);
        }
        int last = st[st.size() - 1];
        int rs = q1(last);
        for(int i = 0; i < (rs - (d - dst[last])) / 2; i++) {
            st.pop_back();
        }
        curr = st[st.size() - 1];
        if(dst[curr] == d) {
            ans(curr);
            return 0;
        }
        curr = q2(curr);
    }
}