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
string S;
ll ans = 0;

bool g(string S) {
    for(int i = 0; i < S.size(); i++) {
        for(int j = 1; i + 2 * j < S.size(); j++) {
            if(S[i] == S[i+j] and S[i] == S[i+2*j]) return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    ll r = 1;
    for(ll l = 0; l < S.size(); l++) {
        if(r == S.size() + 1) break;
        while(r != (S.size() + 1) and !g(S.substr(l, r - l))) r++;
        ans += S.size() - r + 1;
    }
    cout << ans << endl;
    return 0;
}