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
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N);
    set<ll> st;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    vector<ll> b(M);
    for(int i = 0; i < M; i++) {
        cin >> b[i];
        st.insert(i);
    }
    sort(a.begin(), a.end(), greater<ll>());
    ll ans = 0;
    for(auto tmp : a) {
        auto itr = st.begin();
        if(itr != st.end() and *itr < tmp) {
            ans += b[*itr];
            st.erase(itr);
        } else {
            ans += b[tmp];
        }
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