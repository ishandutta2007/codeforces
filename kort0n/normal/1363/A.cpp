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
    ll n, x;
    cin >> n >> x;
    bool exist[2] = {false, false};
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum += a;
        exist[a%2] = true;
    }
    if(x == n) {
        if(sum & 1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
        return;
    }
    if(exist[0] and exist[1]) {
        cout << "Yes" << endl;
        return;
    }
    if(!exist[1]) {
        cout << "No" << endl;
        return;
    }
    if(x & 1) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}