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
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    ll difl = 1e9;
    ll difr = -1e9;
    ll dif = 0;
    for(ll i = 0; i < N; i++) {
        if(a[i] == i) continue;
        chmin(difl, i);
        chmax(difr, i);
        dif++;
    }
    ll ans;
    if(dif == 0) {
        ans = 0;
    } else if(difr - difl + 1 == dif) {
        ans = 1;
    } else {
        ans = 2;
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