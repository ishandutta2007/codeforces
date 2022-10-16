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
int a[500][500];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    int multi = -1;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            cin >> a[h][w];
            if(a[h][w] != a[h][0]) multi = h;
        }
    }
    if(multi == -1) {
        int tmp = 0;
        for(int h = 0; h < H; h++) tmp ^= a[h][0];
        if(tmp == 0) {
            cout << "NIE" << endl;
        } else {
            cout << "TAK" << endl;
            for(int i = 0; i < H; i++) {
                if(i != 0) cout << " ";
                cout << 1;
            }
            cout << endl;
        }
        return 0;
    }
    cout << "TAK" << endl;
    vector<int> ans(H);
    int tmp = 0;
    for(int h = 0; h < H; ++h) {
        if(h == multi) continue;
        ans[h] = 0;
        tmp ^= a[h][0];
    }
    for(int w = 0; w < W; w++) {
        if(tmp != a[multi][w]) ans[multi] = w;
    }
    for(int i = 0; i < H; i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
    }
    cout << endl;
    return 0;
}