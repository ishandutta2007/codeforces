#include <bits/stdc++.h>
//#include <atcoder/all>
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
ll H, W, ans;
ll A[505][505];
ll S[505][505];
void solve() {
    ans = 0;
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        string T;
        cin >> T;
        for(int w = 0; w < W; w++) {
            if(T[w] == '*') A[h][w] = 1;
            else A[h][w] = 0;
            S[h][w+1] = S[h][w] + A[h][w];
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            if(A[h][w] == 0) continue;
            ans++;
            for(int i = 1; ; i++) {
                ll nowh = h + i;
                ll l = w - i;
                ll r = w + i;
                if(nowh >= H) break;
                if(l < 0) break;
                if(r >= W) break;
                if(S[nowh][r+1] - S[nowh][l] != r - l + 1) break;
                ans++;
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}