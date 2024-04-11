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
int H, W;
int ans;
string field[500];
void solve() {
    cin >> H >> W;
    ans = 0;
    for(int h = 0; h < H; h++) {
        cin >> field[h];
    }
    for(int w = 0; w < W; w++) {
        if(field[H-1][w] == 'D') ans++;
    }
    for(int h = 0; h < H; h++) {
        if(field[h][W-1] == 'R') ans++;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}