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
const ll MAX_N = 200000;
typedef bitset<MAX_N> BITS;
vector<l_l> edges[MAX_N];
vector<ll> inv[MAX_N];
BITS state[9][9];
bool BANNED[9][9][9][9];
bool NG[9][9];
vector<ll> v;
ll N, M, K;
ll ans;

void f() {
    for(int i = 0; i < K; i++) {
        if(NG[i][v[i]]) return;
        for(int j = i + 1; j < K; j++) {
            if(BANNED[i][v[i]][j][v[j]]) return;
        }
    }
    ans++;
}

void dfs(int idx) {
    if(idx == K) {
        f();
        return;
    }
    for(int i = 0; i <= idx; i++) {
        v[idx] = i;
        dfs(idx + 1);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    v.resize(K);
    for(int i = 0; i < M; i++) {
        ll a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        edges[a].push_back({w, b});
        inv[b].push_back(a);
    }
    for(int i = 0; i < N; i++) {
        sort(edges[i].begin(), edges[i].end());
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < edges[i].size(); j++) {
            int to = edges[i][j].second;
            if(state[edges[i].size()-1][j][to]) NG[edges[i].size()-1][j] = true;
            state[edges[i].size()-1][j][to] = 1;
        }
    }
    /*
    for(int i = 0; i < K; i++) {
        for(int j = 0; j <= i; j++) {
            cout << i << " " << j << " " << state[i][j] << endl;
        }
    }
    */
    for(int i = 0; i < K; i++) {
        for(int j = 0; j <= i; j++) {
            for(int k = i; k < K; k++) {
                for(int l = 0; l <= k; l++) {
                    BITS a = state[i][j] & state[k][l];
                    if(a.count() >= 1) {
                        //cerr << i << " " << j << " " << k << " " << l << endl;
                        BANNED[i][j][k][l] = true;
                    }
                }
            }
        }
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}