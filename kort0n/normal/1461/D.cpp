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
set<ll> st;
vector<ll> a, sum;

void f(int l, int r) {
    if(l >= r) return;
    st.insert(sum[r] - sum[l]);
    ll mid = (a[l] + a[r-1]) / 2;
    auto itr = upper_bound(a.begin(), a.end(), mid);
    int idx = itr - a.begin();
    if(idx != r) f(l, idx);
    if(idx != l) f(idx, r);
}

void solve() {
    st.clear();
    ll N, Q;
    cin >> N >> Q;
    a.resize(N);
    sum.resize(N + 1);
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for(int i = 0; i < N; i++) {
        sum[i+1] = sum[i] + a[i];
    }
    f(0, N);
    for(int q = 0; q < Q; q++) {
        ll s;
        cin >> s;
        if(st.find(s) != st.end()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}