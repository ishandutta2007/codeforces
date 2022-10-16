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
void solve() {
    ll N;
    string S;
    cin >> N >> S;
    string ans = "NO";
    string T = "2020";
    for(int i = 0; i <= 4; i++) {
        bool ok = true;
        string A;
        for(int j = 0; j < 4; j++) {
            if(j < i) A.push_back(S[j]);
            else {
                ll idx = N - 1 - (3 - j);
                A.push_back(S[idx]);
            }
        }
        if(A == T) ans = "YES";
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}