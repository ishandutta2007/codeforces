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

ll a[500][500];
void solve() {
    ll H, W;
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cin >> a[h][w];
        }
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            ll num = 0;
            if(h > 0) num++;
            if(h + 1 < H) num++;
            if(w > 0) num++;
            if(w + 1 < W) num++;
            if(a[h][w] > num) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            ll num = 0;
            if(h > 0) num++;
            if(h + 1 < H) num++;
            if(w > 0) num++;
            if(w + 1 < W) num++;
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}