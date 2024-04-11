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
    vector<l_l> v;
    vector<ll> L(N), R(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i] >> R[i];
        L[i]--;
        v.push_back({L[i], R[i]});
    }
    sort(L.begin(), L.end());
    sort(R.begin(), R.end());
    ll del = N;
    for(int i = 0; i < N; i++) {
        ll tmp = 0;
        auto itr = lower_bound(L.begin(), L.end(), v[i].second);
        tmp += L.end() - itr;
        itr = upper_bound(R.begin(), R.end(), v[i].first);
        tmp += itr - R.begin();
        chmin(del, tmp);
    }
    cout << del << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}