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
vector<ll> paths[105000];
ll p[100500];
ll M, m;
ll depth[100050];
void dfs(int now) {
    ll num = 0;
    for(auto to : paths[now]) {
        if(to == p[now]) continue;
        depth[to] = depth[now] + 1;
        p[to] = now;
        dfs(to);
        if(paths[to].size() == 1) num++;
    }
    if(num) M -= num - 1;
}

int main() {
    ll N;
    cin >> N;
    M = N - 1;
    m = 1;
    for(int i = 0; i < N - 1; i++) {
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    ll root = 0;
    for(int i = 0; i < N; i++) {
        if(paths[i].size() >= 2) root = i;
    }
    p[root] = -1;
    dfs(root);
    set<ll> st;
    for(int i = 0; i < N; i++) {
        if(paths[i].size() == 1) {
            st.insert(depth[i] % 2);
        }
    }
    if(st.size() >= 2) m = 3;
    cout << m << " " << M << endl;
    return 0;
}