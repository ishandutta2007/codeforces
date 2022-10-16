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
int N, M;
vector<int> paths[200100];
vector<int> children[200100];
int p[200100];

int k[200100];
vector<int> query[200100];
bool clear[200100];

void dfs0(int now) {
    for(auto to : paths[now]) {
        if(to == p[now]) continue;
        p[to] = now;
        children[now].push_back(to);
        dfs0(to);
    }
}
int num[200100];
void dfs1(int now) {
    for(auto q : query[now]) {
        num[q]++;
        if(num[q] == k[q]) clear[q] = true;
    }
    for(auto to : children[now]) {
        dfs1(to);
    }
    for(auto q : query[now]) {
        num[q]--;
        if(num[q] == k[q]) clear[q] = true;
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        paths[u].push_back(v);
        paths[v].push_back(u);
    }
    dfs0(0);
    for(int i = 0; i < M; i++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            int u;
            cin >> u;
            u--;
            if(u != 0) {
                u = p[u];
            }
            query[u].push_back(i);
        }
    }
    dfs1(0);
    for(int i = 0; i < M; i++) {
        if(clear[i]) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}