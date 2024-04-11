#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
ll N;
vector<l_l> edges;
vector<int> anse;
struct EulerianGraph {
    vector< vector< pair<int, int> > > a;
    int num_edges;
 
    EulerianGraph(int n) {
        a.resize(n + 1);
        num_edges = 0;
    }
 
    void add_edge(int u, int v, bool undirected = true) {
        a[u].push_back(make_pair(v, num_edges));
        if (undirected) a[v].push_back(make_pair(u, num_edges));
        num_edges++;
    }
 
    vector<int> get_eulerian_path(int startNode) {
        vector<int> path, s;
        vector<bool> was(num_edges);
        s.push_back(startNode); // start of eulerian path
        while (!s.empty()) {
            int u = s.back();
            bool found = false;
            while (!a[u].empty()) {
                int v = a[u].back().first;
                int e = a[u].back().second;
                a[u].pop_back();
                if (was[e]) continue;
                was[e] = true;
                anse.push_back(e);
                s.push_back(v);
                found = true;
                break; 
            }
            if (!found) {
                path.push_back(u);
                s.pop_back();
            }
        }
        reverse(path.begin(), path.end());
        reverse(anse.begin(), anse.end());
        return path;
    }
};


void f(int k) {
    anse.clear();
    EulerianGraph ET((1<<k));
    for(int i = 0; i < edges.size(); i++) {
        int a = edges[i].first % (1 << k);
        int b = edges[i].second % (1 << k);
        ET.add_edge(a, b);
    }
    for(int i = 0; i < (1 << k); i++) {
        //cerr << k << " " << i << " " << ET.a[i].size() << endl;
        if(ET.a[i].size() % 2) return;
    }
    int s = edges[0].first % (1 << k);
    vector<int> v = ET.get_eulerian_path(s);
    if(v.size() != N + 1) return;
    cout << k << endl;
    /*
    for(auto e : anse) {
        cout << e << " ";
    }
    cout << endl;
    */
    vector<int> ans;
    map<i_i, vector<i_i>> mp;
    vector<bool> used(N);
    for(int i = 0; i < N; i++) {
        int a = edges[i].first % (1 << k);
        int b = edges[i].second % (1 << k);
        mp[{a, b}].push_back({2*i, 2*i+1});
        mp[{b, a}].push_back({2*i+1, 2*i});
    }
    for(int i = 0; i < N; i++) {
        while(true) {
            auto tmp = mp[{v[i], v[i+1]}].back();
            int idx = tmp.first / 2;
            if(used[idx]) {
                mp[{v[i], v[i+1]}].pop_back();
                continue;
            }
            mp[{v[i], v[i+1]}].pop_back();
            used[idx] = true;
            ans.push_back(tmp.first);
            ans.push_back(tmp.second);
            break;
        }
    }
    /*
    int now = s;
    for(int T = 1; T <= N; T++) {
        int nowe = anse[T-1];
        if(edges[nowe].first % (1<<k) == now) {
            ans.push_back(nowe * 2);
            ans.push_back(nowe * 2 + 1);
            now = edges[nowe].second % (1<<k);
        } else {
            ans.push_back(nowe * 2 + 1);
            ans.push_back(nowe * 2);
            now = edges[nowe].first % (1<<k);
        }
    }
    */
    for(auto v : ans) {
        cout << v + 1 << " ";
    }
    cout << endl;
    exit(0);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    edges.resize(N);
    for(int i = 0; i < N; i++) {
        l_l a;
        cin >> a.first >> a.second;
        edges[i] = a;
    }
    for(int k = 20; k >= 0; k--) {
        f(k);
    }
    return 0;
}