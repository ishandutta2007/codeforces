#include <bits/stdc++.h>

using namespace std;

vector<int> dsu;

int find_set(int v) {
    if (v == dsu[v]) return v;
    return dsu[v] = find_set(dsu[v]);
}

void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (rand() % 2) swap(a, b);
    dsu[a] = b;
}

vector< vector<int> > graph;
vector<int> components;
vector<int> color;

void dfs(int v) {
    if (color[v] == 2) return;
    if (color[v] == 1) {
        components[find_set(v)] = 1;
        return;
    }
    color[v] = 1;
    for (auto u: graph[v]) {
        dfs(u);
    }
    color[v] = 2;
}

int main() {
    srand(time(0));
    
    int n, m;
    cin >> n >> m;
    
    dsu.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
    }
    
    graph.assign(n + 1, vector<int>()); 
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        unite(a, b);
    }
    
    components.assign(n + 1, 0);
    color.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        dfs(i);
    }
    
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i == find_set(i)) result += components[i];
        else result++;
    }
    
    
    cout << result << endl;
}