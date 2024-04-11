#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

void solve() {
    ll n;
    cin >> n;
    map<ll, l_l> mp;
    set<ll> st;
    for(int i = 1; i <= n; i++) {
        ll a, f;
        cin >> a;
        f = 1;
        st.insert(a);
        mp[a].first++;
        if(f == 1) mp[a].second++;
    }
    vector<l_l> v;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        v.push_back(mp[*itr]);
    }
    v.push_back({-1, -1});
    sort(v.begin(), v.end());
    ll val = v.back().first;
    l_l ans = {0, 0};
    multiset<ll> remain;
    while(val > 0) {
        while(v.back().first >= val) {
            remain.insert(v.back().second);
            v.pop_back();
        }
        auto itr = remain.end();
        itr--;
        ans.first += val;
        ans.second += min(*itr, val);
        remain.erase(itr);
        if(remain.empty()) {
            val = v.back().first;
        } else val--;
    }
    cout << ans.first << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll q;
    cin >> q;
    while(q--) solve();
    return 0;
}