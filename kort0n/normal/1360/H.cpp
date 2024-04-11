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
    ll N, M;
    cin >> N >> M;
    ll ok = 0;
    ll ng = (1LL << M);
    vector<ll> v;
    for(int i = 0; i < N; i++) {
        string S;
        cin >> S;
        ll a = 0;
        for(ll j = 0; j < M; j++) {
            if(S[M-1-j] == '1') {
                a += (1LL << j);
            }
        }
        v.push_back(a);
    }
    sort(v.begin(), v.end());
    ll under = ((1LL << M) - N - 1) / 2;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        ll num = mid;
        auto itr = lower_bound(v.begin(), v.end(), mid);
        num -= itr - v.begin();
        if(num <= under) ok = mid;
        else ng = mid;
    }
    string ans;
    for(int i = 0; i < M; i++) {
        if(ok & (1LL << i)) {
            ans = "1" + ans;
        } else {
            ans = "0" + ans;
        }
    }
    cout << ans << endl;
    //cerr << under << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}