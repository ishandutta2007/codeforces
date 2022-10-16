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
    ll N, K;
    string S;
    cin >> N >> K >> S;
    ll onenum = 0;
    ll zeronum = 0;
    bool ok = true;
    for(int i = 0; i < K; i++) {
        bool one = false;
        bool zero = false;
        for(int j = i; j < N; j += K) {
            if(S[j] == '0') zero = true;
            if(S[j] == '1') one = true;
        }
        if(one and zero) ok = false;
        if(one) onenum++;
        if(zero) zeronum++;
    }
    if(onenum > K / 2) ok = false;
    if(zeronum > K / 2) ok = false;
    if(ok) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}