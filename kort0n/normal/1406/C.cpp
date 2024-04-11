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
ll N;
vector<ll> edges[105000];
vector<ll> children[105000];
ll sz[105000];
ll p[105000];
void dfs(int now) {
    sz[now] = 1;
    for(auto to : edges[now]) {
        if(to == p[now]) continue;
        children[now].push_back(to);
        p[to] = now;
        dfs(to);
        sz[now] += sz[to];
    }
    sort(children[now].begin(), children[now].end(), [&](ll a, ll b){
        return sz[a] > sz[b];
    });
    /*
    for(auto tmp : children[now]) cerr << tmp << " ";
    cerr << endl;
    */
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        edges[i].clear();
        children[i].clear();
    }
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    p[0] = -1;
    dfs(0);
    ll c = 0;
    while(children[c].size()) {
        if(sz[children[c][0]] * 2 > N) c = children[c][0];
        else break;
    }
    ll b = c;
    while(children[b].size()) b = children[b][0];
    cout << b + 1 << " " << p[b] + 1 << endl;
    cout << c + 1 << " " << b + 1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}