#include <bits/stdc++.h>
//#include <atcoder/all>
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
        return path;
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    EulerianGraph EG(K);
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) {
            if(j == i) continue;
            EG.add_edge(i, j, false);
        }
    }
    auto v = EG.get_eulerian_path(0);
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < v.size(); j++) {
            if(v[j] == i) {
                v.insert(v.begin() + j, i);
                break;
            }
        }
    }
    set<i_i> st;
    for(int i = 0; i + 1 < (int)v.size(); i++) {
        st.insert({v[i], v[i+1]});
    }
    /*
    for(auto tmp : v) {
        cerr << tmp << " ";
    }
    cerr << endl;
    */
    assert((int)v.size() == K * K + 1);
    assert((int)st.size() == K * K);
    vector<int> ans;
    for(int i = 0; i < N; i++) {
        int idx = i % (v.size() - 1);
        ans.push_back(v[idx]);
        cout << (char)('a' + v[idx]);
    }
    cout << endl;
    return 0;
}