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

void solve() {
    ll N, K;
    cin >> N >> K;
    UnionFind uni(N);
    string S;
    cin >> S;
    for(int i = 0; i < N; i++) {
        uni.merge(i, N - 1 - i);
    }
    for(int i = 0; i < N - K; i++) {
        uni.merge(i, i + K);
    }
    map<int, vector<int>> mp;
    for(int i = 0; i < N; i++) {
        mp[uni.root(i)].push_back(i);
    }
    int ans = 0;
    for(auto tmp : mp) {
        auto v = tmp.second;
        int num = 0;
        int maxi = 0;
        vector<int> u(26);
        for(auto idx : v) {
            u[(int)(S[idx] - 'a')]++;
        }
        for(int i = 0; i < 26; i++) {
            num += u[i];
            chmax(maxi, u[i]);
        }
        ans += num - maxi;
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}