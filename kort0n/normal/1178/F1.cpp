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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 998244353;
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

ll N, M;
ll c[1505];
ll dp[1505][1505];
ll pos[1505];
ll lsum[1505];
ll rsum[1505];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> c[i];
        pos[c[i]] = i;
    }
    UnionFind uni(1501);
    for(int i = 0; i <= N + 1; i++) dp[i][0] = 1;
    for(int val = N; val >= 1; val--) {
        dp[pos[val]][0] = 0;
        int r = uni.root(pos[val] + 1);
        int l = uni.root(pos[val] - 1);
        for(int i = 0; i <= 1e3; i++) {
            lsum[i] = 0;
            rsum[i] = 0;
        }
        for(int li = N; li >= 0; li--) {
            lsum[li] = lsum[li+1] + dp[l][li];
            lsum[li] %= mod;
        }
        for(int ri = N; ri >= 0; ri--) {
            rsum[ri] = rsum[ri+1] + dp[r][ri];
            rsum[ri] %= mod;
        }
        for(int ri = 0; ri <= N; ri++) {
            for(int li = 0; li <= N; li++) {
                dp[pos[val]][ri + li + 1] += rsum[ri] * lsum[li];
                dp[pos[val]][ri + li + 1] %= mod;
            }
        }
        for(int i = 0; i <= N; i++) {
            //cerr << pos[val] << " " << i << " " << dp[pos[val]][i] << endl;
        }
        //cerr << val << " " << r << " " << l << endl;
        if(c[r] > val) uni.par[r] = pos[val];
        if(c[l] > val) uni.par[l] = pos[val];
    }
    ll ans = 0;
    for(int i = 0; i <= N; i++) {
        ans += dp[pos[1]][i];
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}