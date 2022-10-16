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
map<int, int> mp;

void solve() {
    mp[0] = 0;
    mp[1] = 1;
    mp[2] = 5;
    mp[5] = 2;
    mp[8] = 8;
    int H, W;
    cin >> H >> W;
    string S;
    cin >> S;
    int h = stoi(S.substr(0, 2));
    int w = stoi(S.substr(3, 2));
    w--;
    while(true) {
        w++;
        if(w == W) {
            w = 0;
            h++;
        }
        if(h == H) {
            h = 0;
        }
        bool ok = true;
        int newh = 0;
        int neww = 0;
        int tmp = h / 10;
        if(mp.count(tmp)) neww += mp[tmp];
        else ok = false;
        tmp = h % 10;
        if(mp.count(tmp)) neww += 10 * mp[tmp];
        else ok = false;
        tmp = w / 10;
        if(mp.count(tmp)) newh += mp[tmp];
        else ok = false;
        tmp = w % 10;
        if(mp.count(tmp)) newh += 10 * mp[tmp];
        else ok = false;
        if(ok and newh < H and neww < W) {
            string a = to_string(h);
            if(a.size() == 1) a = "0" + a;
            string b = to_string(w);
            if(b.size() == 1) b = "0" + b;
            cout << a << ":" << b << endl;
            return;
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}