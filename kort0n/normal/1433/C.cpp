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
    cin >> N;
    vector<ll> a(N);
    ll maxi = 0;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        chmax(maxi, a[i]);
    }
    for(int i = 0; i < N; i++) {
        if(a[i] != maxi) continue;
        if(i != 0 and a[i] > a[i-1]) {
            cout << i + 1 << endl;
            return;
        }
        if(i != N - 1 and a[i] > a[i+1]) {
            cout << i + 1 << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}