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
const double PI = acos(-1.0L);
//const ll mod = 1000000007;
ll N, M, Q;
vector<ll> paths[100000];
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

map<ll, vector<ll>> mp;
vector<ll> Poly[100000];
vector<ll> PolySum[100000];
vector<ll> EffectSum[100000];
map<l_l, double> memo;

ll dist[2][100000];

ll dfs(ll idx, ll now, ll from) {
    for(auto to : paths[now]) {
        if(to == from) continue;
        dist[idx][to] = dist[idx][now] + 1;
        dfs(idx, to, now);
    }
}

UnionFind uni;
double f(ll a, ll b) {
    if(Poly[a].size() > Poly[b].size()) swap(a, b);
    double sum = 0;
    sum = EffectSum[a].back() * uni.size(b) + EffectSum[b].back() * uni.size(a) + uni.size(a) * uni.size(b);
    ll d = Poly[b].size() - 1;
    ll minusnum = 0;
    //cerr << sum << endl;
    for(int i = 0; i < Poly[a].size(); i++) {
        ll num = PolySum[b][d-i];
        minusnum += Poly[a][i] * num;
        sum -= i * Poly[a][i] * num;
    }
    sum -= minusnum;
    sum += minusnum * d;
    //cerr << sum << endl;
    //cerr << "A: " << minusnum << " " << d << endl;
    for(int i = 0; i < Poly[a].size(); i++) {
        ll num = PolySum[a][i];
        sum -= (d-i)*Poly[b][d-i]*num;
        //cerr << i << " " << sum << endl;
    }
    ll asz = Poly[a].size();
    ll bnum = EffectSum[b][d-Poly[a].size()+1];
    //cerr << bnum << endl;
    sum -= bnum * uni.size(a);
    //cerr << sum << endl;
    //cerr << sum << endl;
    return sum;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> Q;
    uni.init(N);
    for(int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
        uni.merge(a, b);
    }
    for(int i = 0; i < N; i++) {
        mp[uni.root(i)].push_back(i);
    }
    for(auto tmp : mp) {
        auto v = tmp.second;
        dfs(1, v[0], -1);
        ll v0 = v[0];
        for(auto tmp : v) {
            if(dist[1][tmp] > dist[1][v0]) v0 = tmp;
        }
        dfs(0, v0, -1);
        ll v1 = v[0];
        for(auto tmp : v) {
            if(dist[0][tmp] > dist[0][v1]) v1 = tmp;
        }
        dist[1][v1] = 0;
        dfs(1, v1, -1);
        ll dmax = 0;
        for(auto tmp : v) {
            for(int i = 0; i < 2; i++) {
                chmax(dmax, dist[i][tmp]);
            }
        }
        Poly[tmp.first].resize(dmax + 1);
        PolySum[tmp.first].resize(dmax + 2);
        EffectSum[tmp.first].resize(dmax + 2);
        for(auto tmp2 : v) {
            ll d = max(dist[0][tmp2], dist[1][tmp2]);
            Poly[tmp.first][d]++;
        }
        for(int i = 0; i <= dmax; i++) {
            PolySum[tmp.first][i+1] = PolySum[tmp.first][i] + Poly[tmp.first][i];
            EffectSum[tmp.first][i+1] = EffectSum[tmp.first][i] + Poly[tmp.first][i] * i;
        }
    }
    /*
    for(int i = 0; i < N; i++) {
        if(Poly[i].empty()) continue;
        cerr << "----" << i << "----" << endl;
        for(auto val : Poly[i]) {
            cerr << val << " ";
        }
        cerr << endl;
    }
    */
    for(int q = 0; q < Q; q++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        a = uni.root(a);
        b = uni.root(b);
        if(a < b) swap(a, b);
        if(uni.issame(a, b)) {
            cout << -1 << "\n";
            continue;
        }
        if(memo.count({a, b})) {
            cout << memo[{a, b}] << "\n";
            continue;
        }
        memo[{a, b}] = f(a, b) / uni.size(a) / uni.size(b);
        cout << fixed << setprecision(20) << memo[{a, b}] << "\n";
    }
    return 0;
}