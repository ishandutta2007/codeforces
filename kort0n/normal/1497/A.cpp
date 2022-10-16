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
    multiset<ll> st;
    vector<ll> ans;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        st.insert(a);
    }
    for(ll i = 0; ; i++) {
        if(st.find(i) == st.end()) break;
        ans.push_back(i);
        auto itr = st.lower_bound(i);
        st.erase(itr);
    }
    for(auto tmp : st) ans.push_back(tmp);
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}