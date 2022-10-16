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
ll H, W;
ll a[105][105];
ll target[105][105];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        string S;
        cin >> S;
        for(int w = 0; w < W; w++) {
            if(S[w] == 'B') target[h][w] = 1;
            else target[h][w] = -1;
        }
    }
    int ans = 0;
    for(int h = H - 1; h >= 0; h--) {
        for(int w = W - 1; w >= 0; w--) {
            if(target[h][w] == a[h][w]) continue;
            ans++;
            int delta = target[h][w] - a[h][w];
            for(int h1 = 0; h1 <= h; h1++) {
                for(int w1 = 0; w1 <= w; w1++) {
                    a[h1][w1] += delta;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}