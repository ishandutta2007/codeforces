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

int H, W;
string field[70];
int ans;
int tate(int w) {
    int ret = 0;
    for(int h = 0; h < H; h++) {
        if(field[h][w] == 'A') ret++;
    }
    return ret;
}

int yoko(int h) {
    int ret = 0;
    for(int w = 0; w < W; w++) {
        if(field[h][w] == 'A') ret++;
    }
    return ret;
}


void solve() {
    cin >> H >> W;
    bool ALL = true;
    bool ALLA = true;
    for(int h = 0; h < H; h++) {
        cin >> field[h];
        for(int w = 0; w < W; w++) {
            if(field[h][w] == 'A') ALL = false;
            else ALLA = false;
        }
    }
    if(ALL) {
        cout << "MORTAL" << endl;
        return;
    }
    if(ALLA) {
        cout << 0 << endl;
        return;
    }
    ans = 4;
    if(tate(0) == H) chmin(ans, 1);
    if(tate(W-1) == H) chmin(ans, 1);
    if(yoko(0) == W) chmin(ans, 1);
    if(yoko(H-1) == W) chmin(ans, 1);
    if(tate(0) > 0) chmin(ans, 3);
    if(tate(W-1) > 0) chmin(ans, 3);
    if(yoko(0) > 0) chmin(ans, 3);
    if(yoko(H-1) > 0) chmin(ans, 3);
    for(int h = 0; h < H; h++) {
        if(yoko(h) == W) chmin(ans, 2);
    }
    for(int w = 0; w < W; w++) {
        if(tate(w) == H) chmin(ans, 2);
    }
    if(field[0][0] == 'A') chmin(ans, 2);
    if(field[0][W-1] == 'A') chmin(ans, 2);
    if(field[H-1][0] == 'A') chmin(ans, 2);
    if(field[H-1][W-1] == 'A') chmin(ans, 2);
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}