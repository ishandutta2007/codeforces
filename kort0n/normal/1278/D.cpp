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
    ll N;
    cin >> N;
    vector<l_l> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    priority_queue<l_l, vector<l_l>, greater<l_l>> que;
    int idx = 0;
    UnionFind uni(N);
    for(int t = 1; t <= 2 * N; t++) {
        if(idx < N and v[idx].first == t) {
            vector<l_l> a;
            while(que.size() and que.top().first < v[idx].second) {
                a.push_back(que.top());
                que.pop();
                if(!uni.merge(idx, a.back().second)) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            while(a.size()) {
                que.push(a.back());
                a.pop_back();
            }
            que.push({v[idx].second, idx});
            idx++;
        } else {
            que.pop();
        }
    }
    if(uni.size(0) == N) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}