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
    ll N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    ll L = N;
    while(L >= 1) {
        if(a[L-1] == L - 1) L--;
        else break;
    }
    //cerr << L << endl;
    double NG = 1;
    for(int q = 0; q < Q; q++) {
        ll l;
        double p;
        cin >> l >> p;
        if(l >= L) {
            NG *= 1 - p;
        }
    }
    double ans;
    if(L == 0) ans = 1;
    else ans = 1 - NG;
    cout << fixed << setprecision(30) << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}