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
ll a[1005][1005];

void solve() {
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for(int j = 0; j < N; j++) {
            a[i][j] = (S[j] == '1');
        }
    }
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        for(int j = 0; j < N; j++) {
            if(S[j] == '1') a[i][j] ^= 1;
        }
    }
    for(int i = 0; i < N; i++) {
        if(a[i][0] == 1) {
            for(int j = 0; j < N; j++) {
                a[i][j] ^= 1;
            }
        }
    }
    string ans = "YES";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(a[i][j] != a[0][j]) ans = "NO";
        }
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