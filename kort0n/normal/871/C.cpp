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
const ll mod = 1000000007;
struct UnionFind {
    vector<int> par;
    vector<int> rank;
    vector<ll> Size;
    vector<bool> IsClosed;
    UnionFind(int n = 1) {
        init(n);
    }

    void init(int n = 1) {
        par.resize(n + 1); rank.resize(n + 1); Size.resize(n + 1);
        IsClosed.resize(n+1);
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
        if (x == y) {
            IsClosed[x] = true;
            return false;
        }
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        Size[x] += Size[y];
        IsClosed[x] = IsClosed[x] or IsClosed[y];
        return true;
    }

    ll size(int x){
        return Size[root(x)];
    }
};

ll inv[10000100];
ll FactorialInv[10000100];
ll Factorial[10000100];
ll beki(ll a, ll b){
    a %= mod;
    if(b == 0){
        return 1;
    }
    ll ans = beki(a, b / 2);
    ans = ans * ans % mod;
    if(b % 2 == 1){
        ans = ans * a % mod;
    }
    return ans;
}
void init_combination(){
    const int MAX = 10000002;
    Factorial[0] = 1;
    inv[0] = 1;
    for(int i = 1; i <= MAX; i++){
        Factorial[i] = Factorial[i - 1] * i % mod;
    }
    FactorialInv[MAX] = beki(Factorial[MAX], mod - 2);
    for(ll i = MAX - 1; i >= 0; i--) {
        FactorialInv[i] = FactorialInv[i+1] * (i+1) % mod;
    }
    for(int i = 1; i <= MAX; i++) {
        inv[i] = FactorialInv[i] * Factorial[i-1] % mod;
    }
}
ll combination(ll a, ll b){
    if((a == b) || (b == 0)){
        return 1;
    }
    if(a < b) return 0;
    ll ans = Factorial[a] * FactorialInv[b] % mod;
    ans = ans * FactorialInv[a - b] % mod;
    return ans;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> x[2];
    vector<ll> cmp[2];
    for(int j = 0; j < 2; j++) {
        x[j].resize(N);
        cmp[j].resize(N);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> x[j][i];
            cmp[j][i] = x[j][i];
        }
    }
    for(int j = 0; j < 2; j++) {
        sort(cmp[j].begin(), cmp[j].end());
        for(int i = 0; i < N; i++) {
            auto itr = lower_bound(cmp[j].begin(), cmp[j].end(), x[j][i]);
            x[j][i] = distance(cmp[j].begin(), itr);
        }
    }
    UnionFind uni(2 * N);
    for(int i = 0; i < N; i++) {
        uni.merge(x[0][i], x[1][i] + N);
    }
    ll ans = 1;
    for(int i = 0; i < 2 * N; i++) {
        if(uni.root(i) != i) continue;
        ll tmp = beki(2, uni.size(i));
        if(!uni.IsClosed[i]) tmp--;
        ans *= tmp;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}