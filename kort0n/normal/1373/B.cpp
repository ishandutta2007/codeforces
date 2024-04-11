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
    ll d = 0;
    ll one = 0;
    ll zero = 0;
    for(auto c : S) {
        if(c == '0') zero++;
        else one++;
    }
    d = min(one, zero);
    if(d % 2 == 0) cout << "NET" << endl;
    else cout << "DA" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    while(N--) solve();
    return 0;
}