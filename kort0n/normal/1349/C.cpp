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
ll dist[1005][1005];
ll H, W, T;
string field[1005];
ll dh[4] = {1, -1, 0, 0};
ll dw[4] = {0, 0, 1, -1};

char change(char a) {
    if(a == '0') return '1';
    else return '0';
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W >> T;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            dist[h][w] = 2e18;
        }
    }
    for(int h = 0; h < H; h++) {
        cin >> field[h];
    }
    queue<i_i> que;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            bool ok = false;
            for(int k = 0; k < 4; k++) {
                int newh = h + dh[k];
                int neww = w + dw[k];
                if(newh < 0 or newh >= H) continue;
                if(neww < 0 or neww >= W) continue;
                if(field[newh][neww] == field[h][w]) ok = true;
            }
            if(ok) {
                dist[h][w] = 0;
                que.push({h, w});
            }
        }
    }
    while(!que.empty()) {
        auto now = que.front();
        que.pop();
        ll nowh = now.first;
        ll noww = now.second;
        for(int k = 0; k < 4; k++) {
            int newh = nowh + dh[k];
            int neww = noww + dw[k];
            if(newh < 0 or newh >= H) continue;
            if(neww < 0 or neww >= W) continue;
            if(chmin(dist[newh][neww], dist[nowh][noww] + 1)) que.push({newh, neww});
        }
    }
    for(int t = 0; t < T; t++) {
        ll h, w, p;
        cin >> h >> w >> p;
        h--;
        w--;
        //cerr << t << " " << h << " " << w << " " << p << endl;
        if(p <= dist[h][w]) {
            cout << field[h][w] << endl;
        } else {
            ll delta = p - dist[h][w];
            char tmp = field[h][w];
            if(delta % 2 == 1) {
                tmp = change(tmp);
            }
            cout << tmp << endl;
        }
    }
    return 0;
}