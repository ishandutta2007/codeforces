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
    ll a, b, c;
    cin >> a >> b >> c;
    string S;
    if(b > 0) {
        for(int i = 0; i < b + 1; i++) {
            S.push_back('0');
            if(i % 2 == 1) S.back()++;
        }
    } else {
        if(a > 0) S = "0";
        else S = "1";
    }
    while(a--) {
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '0') {
                S.insert(S.begin() + i, '0');
                break;
            }
        }
    }
    while(c--) {
        for(int i = 0; i < S.size(); i++) {
            if(S[i] == '1') {
                S.insert(S.begin() + i, '1');
                break;
            }
        }
    }
    cout << S << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}