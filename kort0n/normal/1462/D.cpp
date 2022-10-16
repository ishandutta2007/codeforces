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
    for(int i = 0; i < N; i++) cin >> a[i];
    ll ans = 0;
    for(ll num = 1; num <= N; num++) {
        ll sum = 0;
        for(int j = 0; j < num; j++) sum += a[j];
        bool ok = true;
        ll tmpans = 0;
        ll tmpval = 0;
        for(int i = 0; i < N; i++) {
            tmpval += a[i];
            if(tmpval == sum) {
                tmpval = 0;
                tmpans++;
            }
            if(tmpval > sum) {
                ok = false;
            }
        }
        if(tmpval != 0) {
            ok = false;
        }
        if(ok) {
            chmax(ans, tmpans);
        }
    }
    cout << N - ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}