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

set<ll> edges[201000];
vector<ll> leaves[200100];
ll N, K;
void solve() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        edges[i].clear();
        leaves[i].clear();
    }
    for(int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    if(K == 1) {
        cout << N - 1 << endl;
        return;
    }
    for(int i = 0; i < N; i++) {
        if(edges[i].size() == 1) {
            ll to = *edges[i].begin();
            leaves[to].push_back(i);
        }
    }
    ll ans = 0;
    queue<ll> que;
    for(int i = 0; i < N; i++) {
        if(leaves[i].size() >= K) que.push(i);
    }
    while(que.size()) {
        auto now = que.front();
        que.pop();
        if(leaves[now].size() < K) continue;
        ans++;
        for(int k = 0; k < K; k++) {
            int tmp = leaves[now].back();
            leaves[now].pop_back();
            edges[now].erase(tmp);
        }
        if(edges[now].size() == 1) {
            int to = *edges[now].begin();
            leaves[to].push_back(now);
            if(leaves[to].size() == K) {
                que.push(to);
            }
        }
        if(leaves[now].size() >= K) {
            que.push(now);
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}