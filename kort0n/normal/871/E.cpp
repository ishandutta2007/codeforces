#include <bits/stdc++.h>
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
int N, K;
vector<int> vertex;
vector<int> d[200];
set<i_i> st;
vector<int> g[30000];
int dist[200][30000];

void dfs(int idx, int now, int from) {
    for(auto to : g[now]) {
        if(to == from) continue;
        dist[idx][to] = dist[idx][now] + 1;
        dfs(idx, to, now);
    }
}

set<int> appear;

map<int, vector<i_i>> children;

struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 1;
    }

    int root(int x) {
        if (par[x] == x) {
            return x;
        }
        else {
            int r = root(par[x]);
            return par[x] = r;
        }
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vertex.resize(K, -1);
    for(int k = 0; k < K; k++) {
        d[k].resize(N);
        for(int i = 0; i < N; i++) {
            cin >> d[k][i];
            if(d[k][i] == 0) {
                if(vertex[k] != -1) {
                    cout << -1 << endl;
                    return 0;
                } else {
                    vertex[k] = i;
                }
            }
        }
        if(vertex[k] == -1) {
            cout << -1 << endl;
            return 0;;
        }
        appear.insert(vertex[k]);
    }
    for(int k = 1; k < K; k++) {
        int mini = d[0][vertex[k]];
        vector<int> v(mini + 1, -1);
        for(int i = 0; i < N; i++) {
            if(d[0][i] + d[k][i] < mini) {
                cout << -1 << endl;
            }
            if(d[0][i] + d[k][i] == mini) {
                if(v[d[0][i]] != -1) {
                    cout << -1 << endl;
                    return 0;;
                }
                v[d[0][i]] = i;
            }
        }
        for(int i = 0; i <= mini; i++) {
            if(v[i] == -1) {
                cout << -1 << endl;
                return 0;;
            }
        }
        for(int i = 0; i < mini; i++) {
            int a = v[i];
            int b = v[i+1];
            if(a > b) swap(a, b);
            st.insert({a, b});
        }
    }
    UnionFind uni(N);
    for(auto tmp : st) {
        if(!uni.merge(tmp.first, tmp.second)) {
            cout << -1 << endl;
            return 0;
        } else {
            g[tmp.first].push_back(tmp.second);
            g[tmp.second].push_back(tmp.first);
            appear.insert(tmp.first);
            appear.insert(tmp.second);
        }
    }
    /*
    for(auto tmp : appear) cerr << tmp << " ";
    cerr << endl;
    for(int k = 0; k < K; k++) {
        dfs(k, vertex[k], -1);
        for(int i = 0; i < N; i++) {
            cerr << dist[k][i] << " ";
        }
        cerr << endl;
    }
    */
    map<vector<int>, int> mp;
    for(int i = 0; i < N; i++) {
        if(appear.find(i) == appear.end()) continue;
        vector<int> v(K);
        int mini = 1e9;
        for(int j = 0; j < K; j++) {
            v[j] = d[j][i];
            chmin(mini, v[j]);
        }
        for(int j = 0; j < K; j++) {
            v[j] -= mini;
        }
        /*
        cerr << "insert: " << i << endl;
        for(auto val : v) {
            cerr << val << " ";
        }
        cerr << endl;
        */
        mp[v] = i;
    }
    for(int i = 0; i < N; i++) {
        if(appear.find(i) != appear.end()) continue;
        vector<int> v(K);
        int mini = 1e9;
        for(int j = 0; j < K; j++) {
            v[j] = d[j][i];
            chmin(mini, v[j]);
        }
        for(int j = 0; j < K; j++) {
            v[j] -= mini;
        }
        /*
        cerr << "check: " << i << endl;
        for(auto val : v) {
            cerr << val << " ";
        }
        cerr << endl;
        */
        if(mp.count(v)) {
            int p = mp[v];
            int len = d[0][i] - d[0][p];
            //cerr << "len: " << len << endl;
            if(len <= 0) {
                cout << -1 << endl;
                return 0;
            }
            children[p].push_back({len, i});
        } else {
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i = 0; i < N; i++) {
        if(children[i].empty()) continue;
        auto v = children[i];
        sort(v.begin(), v.end());
        if(v[0].first != 1) {
            cout << -1 << endl;
            return 0;
        }
        int Last = i;
        st.insert({i, v[0].second});
        g[Last].push_back(v[0].second);
        g[v[0].second].push_back(Last);
        for(int i = 1; i < v.size(); i++) {
            if(v[i].first > v[i-1].first + 1) {
                cout << -1 << endl;
                return 0;
            } else if(v[i].first == v[i-1].first) {
                st.insert({Last, v[i].second});
                g[Last].push_back(v[i].second);
                g[v[i].second].push_back(Last);
            } else {
                Last = v[i-1].second;
                st.insert({Last, v[i].second});
                g[Last].push_back(v[i].second);
                g[v[i].second].push_back(Last);
            }
        }
    }
    for(int i = 0; i < K; i++) {
        dfs(i, vertex[i], -1);
        for(int j = 0; j < N; j++) {
            if(dist[i][j] != d[i][j]) {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    for(auto e : st) {
        cout << e.first + 1 << " " << e.second + 1 << endl;
    }
    return 0;
}