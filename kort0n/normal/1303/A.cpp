#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

void solve() {
    string S;
    cin >> S;
    int l = S.size();
    int r = -1;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '1') {
            chmax(r, i);
            chmin(l, i);
        }
    }
    if(r == -1) {
        cout << 0 << endl;
        return;
    }
    int ans = 0;
    for(int i = l; i < r; i++) {
        if(S[i] == '0') ans++;
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}