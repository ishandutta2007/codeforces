#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
int n, m;
vector<vector<int>> g;
vector<int> deg, dead;

vector<int> inv(vector<int> perm) {
    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[perm[i]] = i+1;
    return a;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        g.assign(n+1, {});
        deg.assign(n+1, 0);
        dead.assign(n+1, 0);
        for(int f, t, i = 0; i < m; i++) {
            cin >> f >> t;f--,t--;
            g[f].push_back(t);
            g[t].push_back(f);
            deg[f]++, deg[t]++;
        }
        vector<int> P, Q, pref;
        set<array<int, 2>> alive;
        for(int i = 0; i < n; i++) {
            sort(all(g[i]));
            alive.insert({-deg[i], i});
            if(deg[i] == n-1) 
                pref.push_back(i);
        }
        auto kill = [&](int i) {
            if(dead[i]) return;
            dead[i] = 1;
            alive.erase({-deg[i], i});
            for(auto &j : g[i]) if(!dead[j]) {
                alive.erase({-deg[j], j});
                deg[j]--;
                alive.insert({-deg[j], j});
            }
        };
        for(auto &i : pref)
            kill(i);
        P = Q = pref;
        while(alive.size()) {
            int v = alive.begin()->at(1);
            kill(v);
            vector<int> x = {v}, y;
            for(auto [_, i] : alive) if(!binary_search(all(g[v]), i))
                y.push_back(i);
            for(auto i : y) kill(i);
            while(alive.size() && 1-alive.begin()->at(0) == alive.size()) {
                x.push_back(alive.begin()->at(1));
                kill(alive.begin()->at(1));
            }
            for(auto i : x) P.push_back(i);
            for(auto i : y) {
                P.push_back(i);
                Q.push_back(i);
            }
            for(auto i : x) Q.push_back(i);
        }
        P = inv(P);
        Q = inv(Q);
        for(auto i : P) cout << i << ' ';cout << '\n';
        for(auto i : Q) cout << i << ' '; cout << '\n';
    }
}