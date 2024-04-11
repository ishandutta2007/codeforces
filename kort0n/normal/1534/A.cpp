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
string str = "RW";
void solve() {
    cin >> H >> W;
    vector<string> S(H);
    for(int h = 0; h < H; h++) cin >> S[h];
    for(int k = 0; k < 2; k++) {
        vector<string> T(H);
        bool ok = true;
        for(int h = 0; h < H; h++) {
            for(int w = 0; w < W; w++) {
                char c = str[(h+w+k)%2];
                T[h].push_back(c);
                if(S[h][w] != '.' and S[h][w] != c) ok = false;
            }
        }
        if(ok) {
            cout << "YES" << endl;
            for(auto s : T) cout << s << endl;
            return;
        }
    }
    cout << "NO" << endl;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}