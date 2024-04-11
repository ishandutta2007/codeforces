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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll H, W;
    cin >> H >> W;
    if(H == 1 and W == 1) {
        cout << 0 << endl;
        return 0;
    }
    if(H == 1) {
        for(int i = 0; i < W; i++) {
            cout << i + 2 << " ";
        }
        cout << endl;
        return 0;
    }
    if(W == 1) {
        for(int i = 0; i < H; i++) {
            cout << i + 2 << endl;
        }
        return 0;
    }
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            int hnum = h + 1;
            int wnum = H + w + 1;
            cout << hnum * wnum << " ";
        }
        cout << endl;
    }
    return 0;
}