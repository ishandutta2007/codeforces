#pragma GCC optimize("Ofast")
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
int dist[1000][1000][40];
int color[1000][1000];
int cdist[40][40];
int H, W, K;
int dh[4] = {1, -1, 0, 0};
int dw[4] = {0, 0, 1, -1};
void bfs(int c) {
    queue<i_i> que;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(color[h][w] == c) {
                dist[h][w][c] = 0;
                que.push({h,w});
            } else {
                dist[h][w][c] = 1e9;
            }
        }
    }
    while(!que.empty()) {
        auto tmp = que.front();
        que.pop();
        int nowh = tmp.first;
        int noww = tmp.second;
        for(int k = 0; k < 4; k++) {
            int newh = nowh + dh[k];
            int neww = noww + dw[k];
            if(newh < 0 or newh >= H) continue;
            if(neww < 0 or neww >= W) continue;
            if(chmin(dist[newh][neww][c], dist[nowh][noww][c] + 1)) {
                que.push({newh, neww});
            }
        }
    }
}

void Dijkstra(int c) {
    queue<i_i> que;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(color[h][w] == c) {
                dist[h][w][c] = 0;
                que.push({h,w});
            } else {
                dist[h][w][c] = 1e9;
            }
        }
    }
    while(!que.empty()) {
        auto tmp = que.front();
        que.pop();
        int nowh = tmp.first;
        int noww = tmp.second;
        for(int k = 0; k < 4; k++) {
            int newh = nowh + dh[k];
            int neww = noww + dw[k];
            if(newh < 0 or newh >= H) continue;
            if(neww < 0 or neww >= W) continue;
            if(chmin(dist[newh][neww][c], dist[nowh][noww][c] + 1)) {
                que.push({newh, neww});
            }
        }
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> K;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cin >> color[h][w];
            color[h][w]--;
        }
    }
    for(int i = 0; i < K; i++) bfs(i);
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) {
            cdist[i][j] = 1e9;
        }
        cdist[i][i] = 0;
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            int c = color[h][w];
            for(int c1 = 0; c1 < K; c1++) {
                chmin(cdist[c][c1], dist[h][w][c1] + 1);
                chmin(cdist[c1][c], dist[h][w][c1] + 1);
            }
        }
    }
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) {
            for(int l = 0; l < K; l++) {
                chmin(cdist[j][l], cdist[j][i] + cdist[i][l]);
            }
        }
    }
    /*
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            for(int c1 = 0; c1 < K; c1++) {
                chmin(dist[h][w][c1], cdist[color[h][w]][c1]);
            }
        }
    }
    */
   /*
    for(int c = 0; c < K; c++) {
        Dijkstra(c);
    }
    */
    /*
    for(int c = 0; c < K; c++) {
        cerr << "----" << c << "----" << endl;
        for(int h = 0; h < H; h++) {
            for(int w = 0; w < W; w++) {
                cerr << dist[h][w][c] << " ";
            }
            cerr << endl;
        }
    }
    */
    int Q;
    cin >> Q;
    while(Q--) {
        int h1, w1, h2, w2;
        cin >> h1 >> w1 >> h2 >> w2;
        h1--;
        w1--;
        h2--;
        w2--;
        for(int c1 = 0; c1 < K; c1++) {
            for(int c2 = 0; c2 < K; c2++) {
                chmin(dist[h1][w1][c2], dist[h1][w1][c1] + cdist[c1][c2]);
                chmin(dist[h2][w2][c2], dist[h2][w2][c1] + cdist[c1][c2]);
            }
        }
        ll ans = abs(h1 - h2) + abs(w1 - w2);
        for(int c = 0; c < K; c++) {
            ll now = dist[h1][w1][c];
            now += dist[h2][w2][c];
            chmin(ans, now + 1);
        }
        cout << ans << "\n";
    }
    return 0;
}