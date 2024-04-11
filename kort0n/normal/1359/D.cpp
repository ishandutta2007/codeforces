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
ll N;
vector<ll> a;
ll ans;
void f(ll border) {
    ll mini = 0;
    ll now = 0;
    ll tmpans = 0;
    for(int i = 0; i < N; i++) {
        if(a[i] > border) {
            now = 0;
            mini = 0;
        } else {
            now += a[i];
            chmin(mini, now);
            chmax(tmpans, now - mini);
        }
    }
    if(border > 0) tmpans -= border;
    chmax(ans, tmpans);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(ll val = 31; val >= -31; val--) f(val);
    cout << ans << endl;
    return 0;
}