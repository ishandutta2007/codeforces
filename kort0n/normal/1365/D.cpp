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

string S[50];
int dh[4] = {1, -1, 0, 0};
int dw[4] = {0, 0, 1, -1};
bool visited[50][50];

void solve() {
    ll H, W;
    cin >> H >> W;
    int g = 0;
    for(int h = 0; h < H; h++) {
        cin >> S[h];
        for(int w = 0; w < W; w++) visited[h][w] = false;
        for(auto c : S[h]) {
            if(c == 'G') g++;
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(S[h][w] != 'B') continue;
            for(int k = 0; k < 4; k++) {
                int newh = h + dh[k];
                int neww = w + dw[k];
                if(newh < 0 or newh >= H or neww < 0 or neww >= W) continue;
                if(S[newh][neww] == 'G') {
                    cout << "No" << endl;
                    return;
                }
                if(S[newh][neww] == '.') {
                    S[newh][neww] = '#';
                }
            }
        }
    }
    queue<i_i> que;
    if(S[H-1][W-1] != '#') que.push({H-1, W-1});
    while(!que.empty()) {
        int nowh = que.front().first;
        int noww = que.front().second;
        que.pop();
        if(visited[nowh][noww]) continue;
        visited[nowh][noww] = true;
        if(S[nowh][noww] == 'G') g--;
        for(int k = 0; k < 4; k++) {
            int newh = nowh + dh[k];
            int neww = noww + dw[k];
            if(newh < 0 or newh >= H or neww < 0 or neww >= W) continue;
            if(S[newh][neww] == '#') continue;
            que.push({newh, neww});

        }
    }
    if(g) cout << "No" << endl;
    else cout << "Yes" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}