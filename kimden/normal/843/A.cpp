#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

vector<int> dsu;

int find(int v){
    if(dsu[v] < 0){
        return v;
    }
    return dsu[v] = find(dsu[v]);
}

void unite(int u, int v){
    u = find(u);
    v = find(v);
    if(u != v){
        if(dsu[u] > dsu[v]){
            swap(u, v);
        }
        dsu[u] += dsu[v];
        dsu[v] = u;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<pii> v, u;
    dsu.resize(n, -1);
    v.resize(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i].first;
        v[i].second = i;
    }
    u = v;
    sort(u.begin(), u.end());
    for(int i = 0; i < n; ++i){
        unite(i, u[i].second);
    }
    map<int, vector<int>> mp;
    for(int i = 0; i < n; ++i){
        mp[find(i)].push_back(i);
    }
    cout << mp.size() << endl;
    for(auto pr : mp){
        cout << pr.second.size();
        for(auto a: pr.second){
            cout << " " << a + 1;
        }
        cout << endl;
    }
    return 0;
}