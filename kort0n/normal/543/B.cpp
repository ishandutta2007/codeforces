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
//const ll mod = 1000000007;
//set<i_i> pathes[3005];
int N, M;
int s[2], t[2], l[2];
int dist[3005][3005];
vector<int> pathes[3005];
int a[3005], b[3005];

void g(int start, int index) {
    for(int i = 1; i <= N; i++) {
        dist[index][i] = 1e9;
    }
    dist[index][start] = 0;
    queue<int> que;
    que.push(start);
    while(!que.empty()) {
        int now = que.front();
        que.pop();
        for(int i = 0; i < pathes[now].size(); i++) {
            int to = pathes[now][i];
            ///cerr << "now: " << start << " " << now << " "<< to << endl;
            if(chmin(dist[index][to], dist[index][now] + 1)) que.push(to);
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 1; i <= M; i++) {
        cin >> a[i] >> b[i];
        pathes[a[i]].push_back(b[i]);
        pathes[b[i]].push_back(a[i]);
    }
    for(int i = 1; i <= N; i++) {
        g(i, i);
    }
    for(int i = 0; i < 2; i++) {
        cin >> s[i] >> t[i] >> l[i];
    }
    int ans = 1e9;
    if(dist[s[0]][t[0]] <= l[0] && dist[s[1]][t[1]] <= l[1]) {
        chmin(ans, dist[s[0]][t[0]] + dist[s[1]][t[1]]);
    } else {
        cout << -1 << endl;
        return 0;
    }
    for(int from = 1; from <= N; from++) {
        for(int to = 1; to <= N; to++) {
            //cerr << from << " " << to << " " << dist[from][to] << endl;
            //int d1 = dist[0][from] + DIST[to] + dist[2][to];
            int d1 = dist[s[0]][from] + dist[from][to] + dist[to][t[0]];
            int d2 = dist[s[1]][from] + dist[from][to] + dist[to][t[1]];
            //cerr << from << " " << to << " " << d1 << " " << d2 << endl;
            //int d2 = dist[1][from] + DIST[to] + dist[3][to];
            if(d1 <= l[0] && d2 <= l[1]) chmin(ans, d1 + d2 - dist[from][to]);
            d2 = dist[s[1]][to] + dist[from][to] + dist[from][t[1]];
            if(d1 <= l[0] && d2 <= l[1]) chmin(ans, d1 + d2 - dist[from][to]);
        }
    }
    if(ans == 1e9) ans = -1;
    else ans = M - ans;
    cout << ans << endl;
    return 0;
}