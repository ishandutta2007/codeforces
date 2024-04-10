#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

const int MAXN = 200000;

vector <int> vec[MAXN+5];
int comp[MAXN+5];
int mnk[MAXN+5];

set <pair <int, int>> pos;

const int INF = 1000000000;

int s;

int comps;

vector <pair <int, int>> graf[MAXN+5];

bool povezi(int a, int b, int k){
    a = comp[a];
    b = comp[b];
    if(a == b) return 0;
    if(vec[a].size() < vec[b].size()) swap(a, b);
    if(comp[s] == a) for(auto c : vec[b]) mnk[c] = k;
    if(comp[s] == b) for(auto c : vec[a]) mnk[c] = k;
    for(auto c : vec[b]){
        vec[a].push_back(c);
        comp[c] = a;
    }
    vec[b].clear();
    return 1;
}

int a[MAXN+5];

struct Edge{
    int a, b, c;
    bool operator <(const Edge &x){
        return c < x.c;
    }
};

void dfs(int v, int p, int w){
    mnk[v] = w;
    for(auto c : graf[v]) if(c.first != p) dfs(c.first, v, max(w, c.second));
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0);
    cout.precision(10);
    cout << fixed;

    int n, qrs, d;
    cin >> n >> qrs >> s >> d;
    for(int i=1; i<=n; i++) cin >> a[i];
    comps = n;
    for(int i=1; i<=n; i++){
        comp[i] = i;
        vec[i].push_back(i);
        pos.insert({a[i], i});
    }
    while(comps > 1){
        vector <Edge> edges;
        for(int cmp=1; cmp<=n; cmp++){
            if(vec[cmp].empty()) continue;
            Edge best = {0, 0, INF};
            for(auto v : vec[cmp]) pos.erase({a[v], v});
            for(auto v : vec[cmp]){
                auto p = pos.lower_bound({a[v] + d, 0});
                if(p != pos.end()){
                    Edge x = {v, p->second, abs(p->first - (a[v] + d))};
                    if(x < best) best = x;
                }
                if(p != pos.begin()){
                    p--;
                    Edge x = {v, p->second, abs(p->first - (a[v] + d))};
                    if(x < best) best = x;
                }
            }
            for(auto v : vec[cmp]){
                auto p = pos.lower_bound({a[v] - d, 0});
                if(p != pos.end()){
                    Edge x = {v, p->second, abs(p->first - (a[v] - d))};
                    if(x < best) best = x;
                }
                if(p != pos.begin()){
                    p--;
                    Edge x = {v, p->second, abs(p->first - (a[v] - d))};
                    if(x < best) best = x;
                }
            }
            if(best.c < INF) edges.push_back(best);
            for(auto v : vec[cmp]) pos.insert({a[v], v});
        }
        for(auto edge : edges){
            if(povezi(edge.a, edge.b, edge.c)){
                graf[edge.a].push_back({edge.b, edge.c});
                graf[edge.b].push_back({edge.a, edge.c});
                comps--;
            }
        }
    }
    dfs(s, 0, 0);
    while(qrs--){
        int x, p;
        cin >> x >> p;
        if(mnk[x] <= p) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}