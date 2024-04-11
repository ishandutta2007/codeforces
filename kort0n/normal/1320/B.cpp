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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
ll N, M;
vector<ll> paths[200100];
vector<ll> paths2[200100];
vector<int> p;
int dist[200100];

void bfs(int s) {
    for(int i = 0; i < N; i++) {
        dist[i] = 1e9;
    }
    queue<int> que;
    dist[s] = 0;
    que.push(s);
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto to : paths[now]) {
            if(chmin(dist[to], dist[now] + 1)) {
                que.push(to);
            }
        }
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        paths[v].push_back(u);
        paths2[u].push_back(v);
    }
    int K;
    cin >> K;
    p.resize(K);
    for(int i = 0; i < K; i++) {
        cin >> p[i];
        p[i]--;
    }
    bfs(p.back());
    //for(int i = 0; i < N; i++) cerr << dist[i] << " ";
    //cerr << endl;
    int maxi = 0;
    int mini = 0;
    for(int i = 0; i < K - 1; i++) {
        int minimum = p[i+1];
        for(auto to : paths2[p[i]]) {
            if(dist[minimum] > dist[to]) minimum = to;
        }
        //cerr << i << " " << minimum << endl;
        if(minimum != p[i+1]) mini++;
        for(auto to : paths2[p[i]]) {
            if(to == p[i+1]) continue;
            if(dist[to] <= dist[p[i+1]]) {
                maxi++;
                break;
            }
        }
    }
    cout << mini << " " << maxi << endl;
    return 0;
}