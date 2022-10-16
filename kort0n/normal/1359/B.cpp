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
void solve() {
    ll H, W, x, y;
    cin >> H >> W >> x >> y;
    chmin(y, 2 * x);
    ll ans = 0;
    while(H--) {
        string S;
        cin >> S;
        for(int w = 0; w < W; w++) {
            if(S[w] == '*') continue;
            if(w < W - 1 and S[w+1] == '.') {
                S[w+1] = '*';
                S[w] = '*';
                ans += y;
            } else {
                S[w] = '*';
                ans += x;
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