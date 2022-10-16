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
    ll n;
    cin >> n;
    string S;
    cin >> S;
    string ans[2];
    bool equal = true;
    for(int i = 0; i < S.size(); i++) {
        if(S[i] == '2') {
            if(equal) {
                ans[0].push_back('1');
                ans[1].push_back('1');
            } else {
                ans[0].push_back('2');
                ans[1].push_back('0');
            }
        }
        if(S[i] == '1') {
            if(equal) {
                ans[0].push_back('0');
                ans[1].push_back('1');
                equal = false;
            } else {
                ans[0].push_back('1');
                ans[1].push_back('0');
            }
        }
        if(S[i] == '0') {
            ans[0].push_back('0');
            ans[1].push_back('0');
        }
    }
    cout << ans[0] << endl;
    cout << ans[1] << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}