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
ll N, M, K;
vector<ll> paths[205000];
vector<ll> a;
ll dist[2][201000];
void bfs(int idx, int s) {
    for(int i = 0; i < N; i++) dist[idx][i] = 1e18;
    dist[idx][s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(auto to : paths[now]) {
            if(chmin(dist[idx][to], dist[idx][now]+1)) {
                que.push(to);
            }
        }
    }
}

vector<ll> maxi;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> K;
    a.resize(K);
    for(int i = 0; i < K; i++) {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        paths[a].push_back(b);
        paths[b].push_back(a);
    }
    bfs(0, 0);
    bfs(1, N-1);
    ll ans = dist[0][N-1];
    vector<l_l> v;
    for(int i = 0; i < K; i++) {
        int now = a[i];
        v.push_back({dist[0][now] - dist[1][now], dist[1][now]});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        //cout << v[i].first + v[i].second << " " << v[i].second << endl;
    }
    maxi.resize(K+1);
    for(int i = 1; i < maxi.size(); i++) {
        maxi[i] = max(maxi[i-1], v[i-1].first + v[i-1].second);
    }
    ll newans = 0;
    for(int i = 1; i < v.size(); i++) {
        ll nowans = maxi[i] + v[i].second + 1;
        chmax(newans, nowans);
    }
    //cerr << ans << " " << newans << endl;
    cout << min(ans, newans) << endl;
    return 0;
}