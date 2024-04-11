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
ll N, Q;
ll p[301000];
vector<ll> children[301000];
ll sz[301000];
ll maxc[301000];
ll center[301000];

void dfs(int now) {
    sz[now] = 1;
    center[now] = now;
    for(auto to : children[now]) {
        dfs(to);
        sz[now] += sz[to];
        if(chmax(maxc[now], sz[to])) {
            center[now] = center[to];
        }
    }
    while(sz[center[now]] * 2 < sz[now]) {
        center[now] = p[center[now]];
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    p[0] = -1;
    for(ll i = 1; i < N; i++) {
        cin >> p[i];
        p[i]--;
        children[p[i]].push_back(i);
    }
    dfs(0);
    for(int q = 0; q < Q; q++) {
        ll v;
        cin >> v;
        v--;
        cout << center[v] + 1 << endl;
    }
    return 0;
}