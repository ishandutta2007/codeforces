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
const ll mod = 1000000007;
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        for (int i = 0; i <= n; ++i) par[i] = i, rank[i] = 0, Size[i] = 0;
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
        Size[x] |= Size[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    UnionFind uni(M);
    vector<ll> ans;
    for(int i = 0; i < N; i++) {
        ll k;
        cin >> k;
        if(k == 1) {
            ll a;
            cin >> a;
            a--;
            a = uni.root(a);
            if(uni.Size[a] == 1) continue;
            else {
                uni.Size[a] = 1;
                ans.push_back(i);
            }
        } else {
            ll a, b;
            cin >> a >> b;
            a--;
            b--;
            a = uni.root(a);
            b = uni.root(b);
            if(a == b) continue;
            if(uni.Size[a] == 1 and uni.Size[b] == 1) continue;
            uni.merge(a, b);
            ans.push_back(i);
        }
    }
    ll val = 1;
    for(int i = 0; i < ans.size(); i++) {
        val = val * 2 % mod;
    }
    cout << val << " " << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    return 0;
}