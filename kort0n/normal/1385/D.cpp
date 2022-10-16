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

ll f(string S, char c) {
    if(S.size() == 1) {
        if(S[0] == c) return 0;
        else return 1;
    }
    ll num1 = 0;
    ll num2 = 0;
    ll n = S.size();
    for(int i = 0; i < n/2; i++) {
        if(S[i] != c) num1++;
        if(S[i+n/2] != c) num2++;
    }
    char nxt = c + 1;
    if(c == 'z') nxt = 'a';
    num1 += f(S.substr(n/2, n/2), nxt);
    num2 += f(S.substr(0, n/2), nxt);
    //cerr << S << " " << c << " " << min(num1, num2) << endl;
    return min(num1, num2);
}

void solve() {
    ll N;
    cin >> N;
    string S;
    cin >> S;
    cout << f(S, 'a') << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}