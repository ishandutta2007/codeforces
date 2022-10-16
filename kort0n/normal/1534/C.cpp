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
const ll mod = 1000000007;

void solve() {
    ll N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) mp[A[i]] = B[i];
    set<ll> st;
    ll C = 0;
    for(ll i = 1; i <= N; i++) {
        if(st.find(i) != st.end()) continue;
        C++;
        ll now = i;
        while(st.find(now) == st.end()) {
            st.insert(now);
            now = mp[now];
        }
    }
    ll ans = 1;
    while(C--) {
        ans = ans * 2 % mod;
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