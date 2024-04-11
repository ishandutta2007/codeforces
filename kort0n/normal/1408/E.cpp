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

typedef pair<ll, l_l> lll;
ll Last[105000];
int main() {
    ll N, M;
    cin >> M >> N;
    for(int i = 0; i < M; i++) {
        Last[i] = -1;
    }
    vector<ll> a(M), b(N);
    for(int i = 0; i < M; i++) cin >> a[i];
    for(int i = 0; i < N; i++) cin >> b[i];
    vector<lll> v;
    for(int i = 0; i < M; i++) {
        ll s;
        cin >> s;
        while(s--) {
            ll d;
            cin >> d;
            d--;
            v.push_back({a[i] + b[d], {i, d}});
        }
    }
    sort(v.begin(), v.end(), greater<lll>());
    ll ans = 0;
    UnionFind uni(N);
    for(auto tmp : v) {
        ll i = tmp.second.first;
        ll j = tmp.second.second;
        //cerr << i << " " << j << endl;
        if(Last[i] == -1) {
            Last[i] = j;
            continue;
        }
        if(uni.merge(Last[i], j)) {
            Last[i] = j;
            continue;
        }
        //cerr << "A" << endl;
        ans += tmp.first;
    }
    cout << ans << endl;
    return 0;
}