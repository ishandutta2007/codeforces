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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    map<ll, ll> mp;
    for(int i = 0; i < N; i++) {
        mp[a[i]] = i;
    }
    map<ll, ll> inv;
    set<ll> st;
    for(int i = 0; i <= 2e5; i++) st.insert(i);
    for(auto tmp : mp) {
        inv[tmp.second] = tmp.first;
        st.erase(tmp.first);
    }
    vector<ll> ans(N);
    for(int i = 0; i < N; i++) {
        auto itr = st.begin();
        ans[i] = *itr;
        st.erase(itr);
        if(inv.count(i)) {
            st.insert(inv[i]);
        }
    }
    for(int i = 0; i <= 2e5; i++) st.insert(i);
    for(int i = 0; i < N; i++) {
        st.erase(ans[i]);
        if(*st.begin() != a[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    for(auto val : ans) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}