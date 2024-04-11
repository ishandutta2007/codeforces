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
    string S;
    cin >> S;
    ll ans = 1e9;
    for(int i = 0; i <= S.size(); i++) {
        ll tmp = 0;
        for(int j = 0; j < i; j++) {
            tmp += S[j] == '1';
        }
        for(int j = i; j < S.size(); j++) {
            tmp += S[j] == '0';
        }
        chmin(ans, tmp);
    }
    for(int i = 0; i <= S.size(); i++) {
        ll tmp = 0;
        for(int j = 0; j < i; j++) {
            tmp += S[j] == '0';
        }
        for(int j = i; j < S.size(); j++) {
            tmp += S[j] == '1';
        }
        chmin(ans, tmp);
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}