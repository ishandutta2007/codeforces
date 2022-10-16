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
int dist[3][205000];
int n, k;
vector<int> pathes[205000];
int v[2];
int color[205000];
bool ondepth[205000];
bool searched[2][205000];
bool ng = false;
void dfs(int now, int from, int index) {
    for(int to: pathes[now]) {
        if(to == from) continue;
        dist[index][to] = dist[index][now] + 1;
        dfs(to, now, index);
    }
}

void search(int now, int from, int c) {
    color[now] = c;
    ondepth[now] = true;
    for(int to:pathes[now]) {
        if(to == from) continue;
        if(dist[0][to] + dist[1][to] != dist[0][now] + dist[1][now]) continue;
        search(to, now, (c % k) + 1);
    }
}

void f(int now) {
    int c = dist[0][now] % k + 1;
    color[now] = c;
    for(auto to:pathes[now]) {
        if(searched[0][to]) continue;
        if(ondepth[to]) continue;
        if(dist[0][to] < dist[0][now]) f(to);
    }
}

void g(int now) {
    int c = color[v[1]];
    c -= dist[1][now];
    c %= k;
    c += k;
    c %= k;
    if(c == 0) c += k;
    //cerr << now << " " << c << endl;
    if(color[now] != 0 && color[now] != c) ng = true;
    color[now] = c;
    for(auto to:pathes[now]) {
        if(searched[1][to]) continue;
        if(ondepth[to]) continue;
        if(dist[1][to] < dist[1][now]) g(to);
    }
}

void print() {
    for(int i = 1; i <= n; i++) {
        cout << color[i] << " ";
    }
    cout << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        pathes[u].push_back(v);
        pathes[v].push_back(u);
    }
    dist[0][1] = 0;
    dfs(1, -1, 0);
    v[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(dist[0][i] > dist[0][v[1]]) v[1] = i; 
    }
    dist[1][v[1]] = 0;
    dfs(v[1], -1, 1);
    v[0] = 1;
    for(int i = 2; i <= n; i++) {
        if(dist[1][i] > dist[1][v[0]]) v[0] = i; 
    }
    dist[0][v[0]] = 0;
    dfs(v[0], -1, 0);
    /*
    for(int index = 0; index <= 1; index++) {
        cerr << "---" << v[index] << "---" << endl;
        for(int i = 1; i <= n; i++) {
            cerr << i << " " << dist[index][i] << endl;
        }
    }
    */
    search(v[0], -1, 1);
    for(int i = 1; i <= n; i++) {
        if(dist[0][i] >= k - 1) {
            if(!searched[0][i] && !ondepth[i]) f(i);
        }
    }
    for(int i = 1; i <= n; i++) {
        if(dist[1][i] >= k - 1) {
            if(!searched[1][i] && !ondepth[i]) g(i);
        }
    }
    if(ng) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    for(int i = 1; i <= n; i++) {
        if(color[i] == 0) color[i] = 1;
    }
    print();
    return 0;
}