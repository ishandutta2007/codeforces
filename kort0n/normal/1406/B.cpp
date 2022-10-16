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
ll ans;
vector<ll> a, b;

void f() {
    for(int i = 0; i <= 5; i++) {
        int j = 5 - i;
        if(a.size() < i) continue;
        if(b.size() < j) continue;
        ll tmp = 1;
        for(int k = 0; k < i; k++) {
            tmp *= a[k];
        }
        for(int k = 0; k < j; k++) {
            tmp *= b[k];
        }
        chmax(ans, tmp);
    }
}

void solve() {
    ans = -INF;
    a.clear();
    b.clear();
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        ll c;
        cin >> c;
        if(c >= 0) a.push_back(c);
        else b.push_back(c);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    f();
    reverse(a.begin(), a.end());
    f();
    reverse(b.begin(), b.end());
    f();
    reverse(a.begin(), a.end());
    f();
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