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

ll N, M;
set<ll> pathes[200100];
ll w[200100];
ll subscore[200100];
bool ERASED[200100];
ll s;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    UnionFind uni(N + 1);
    for(int i = 1; i <= N; i++) cin >> w[i];
    for(int i = 1; i <= M; i++) {
        ll a, b;
        cin >> a >> b;
        pathes[a].insert(b);
        pathes[b].insert(a);
        uni.merge(a, b);
    }
    cin >> s;
    queue<int> que;
    for(int i = 1; i <= N; i++) {
        if(pathes[i].size() == 1) {
            que.push(i);
        }
    }
    while(!que.empty()) {
        ll now = que.front();
        que.pop();
        if(now == s) continue;
        if(pathes[now].empty()) continue;
        ERASED[now] = true;
        ll nowcost = subscore[now];
        ll to = *(pathes[now].begin());
        pathes[now].clear();
        auto itr = pathes[to].lower_bound(now);
        pathes[to].erase(itr);
        chmax(subscore[to], nowcost + w[now]);
        if(pathes[to].size() == 1) que.push(to);
    }
    ll ans = 0;
    ll subans = 0;
    for(int i = 1; i <= N; i++) {
        if(!uni.issame(i, s)) continue;
        if(ERASED[i]) continue;
        ans += w[i];
        chmax(subans, subscore[i]);
    }
    cout << ans + subans << endl;
    return 0;
}