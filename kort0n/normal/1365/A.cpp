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
    int H, W;
    cin >> H >> W;
    set<int> st1, st2;
    for(int h = 0; h < H; h++) {
        for(int w = 0; w < W; w++) {
            int a;
            cin >> a;
            if(a == 1) {
                st1.insert(h);
                st2.insert(w);
            }
        }
    }
    int num = min(H - st1.size(), W - st2.size());
    if(num & 1) cout << "Ashish" << endl;
    else cout << "Vivek" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}