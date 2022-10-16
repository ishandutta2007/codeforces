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
ll H, W;
string field[2000];
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
    cin >> H >> W;
    for(int i = 0; i < H; i++) {
        cin >> field[i];
    }
    bool EmptyRow = false;
    bool EmptyColumn = false;
    bool NG = false;
    for(int h = 0; h < H; h++) {
        bool now = false;
        bool after = false;
        for(int w = 0; w < W; w++) {
            if(field[h][w] == '#') now = true;
            if(now and field[h][w] == '.') after = true;
            if(after and field[h][w] == '#') NG = true;
        }
        if(!now) EmptyRow = true;
    }
    for(int w = 0; w < W; w++) {
        bool now = false;
        bool after = false;
        for(int h = 0; h < H; h++) {
            if(field[h][w] == '#') now = true;
            if(now and field[h][w] == '.') after = true;
            if(after and field[h][w] == '#') NG = true;
        }
        if(!now) EmptyColumn = true;
    }
    if(EmptyRow ^ EmptyColumn) {
        NG = true;
    }
    if(NG) {
        cout << -1 << endl;
        return 0;
    }
    UnionFind uni(H * W);
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(field[h][w] == '.') continue;
            if(h > 0 and field[h-1][w] == '#') {
                uni.merge((h-1)*W+w, h*W+w);
            }
            if(w > 0 and field[h][w-1] == '#') {
                uni.merge((h)*W+w-1, h*W+w);
            }
        }
    }
    int ans = 0;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            int num = h * W + w;
            if(field[h][w] == '#' and uni.root(num) == num) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}