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

bool f(vector<ll> v, ll border) {
    ll l = border;
    ll r = v.size() - 1;
    ll m = -1;
    while(r >= l) {
        if(v[l] < v[r]) {
            if(v[l] < m) return false;
            m = v[l];
            l++;
            continue;
        } else {
            if(v[r] < m) return false;
            m = v[r];
            r--;
            continue;
        }
    }
    return true;
}

void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    ll ok = N;
    ll ng = -1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(a, mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}