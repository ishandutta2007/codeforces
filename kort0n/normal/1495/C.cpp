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
ll H, W;
string A[505];
string S[505];
void solve() {
    cin >> H >> W;
    for(int h = 0; h < H; h++) {
        cin >> A[h];
        S[h] = A[h];
    }
    for(int h = 0; h < H; h += 3) {
        S[h] = string(W, 'X');
    }
    for(int h = 2; h < H; h += 3) {
        if(h + 1 < H) {
            bool changed = false;
            for(int w = 0; w < W; w++) {
                if(!changed and S[h-1][w] == 'X') {
                    S[h][w] = 'X';
                    changed = true;
                    break;
                }
                if(!changed and S[h][w] == 'X') {
                    S[h-1][w] = 'X';
                    changed = true;
                    break;
                }
            }
            if(!changed) {
                S[h][0] = S[h-1][0] = 'X';
            }
        } else {
            for(int w = 0; w < W; w++) {
                if(S[h][w] == 'X') {
                    S[h-1][w] = 'X';
                }
            }
        }
    }
    for(int h = 0; h < H; h++) cout << S[h] << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}