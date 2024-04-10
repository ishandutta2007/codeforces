#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using pii = pair<int,int>;

vector<int> a, b;
vector<int> p;
vector<int> sz;

int find_set(int v) {
    if (p[v] == -1) {
        return v;
    }
    return p[v] = find_set(p[v]);
}

void union_sets(int u, int v){
    u = find_set(u);
    v = find_set(v);
    if(u != v){
        if(sz[u] > sz[v]){
            swap(u, v);
        }
        p[u] = v;
        sz[v] += sz[u];
    }
}

vector<int> deg;


int main() {
    int n, m;
    cin >> n >> m;
    int x, y;
    p.resize(n, -1);
    sz.resize(n, 1);
    deg.resize(n, 0);
    for(int i = 0; i < m; ++i){
        cin >> x >> y;
        x--;
        y--;
        deg[x]++;
        deg[y]++;
        a.push_back(x);
        b.push_back(y);
        union_sets(x, y);
    }
    for(int i = 0; i < n; ++i){
        if(deg[i] != sz[find_set(i)] - 1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}