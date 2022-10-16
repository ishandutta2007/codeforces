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
    vector<l_l> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
        if(v[i].first > v[i].second) {
            swap(v[i].first, v[i].second);
        }
    }
    vector<ll> idx(N);
    for(int i = 0; i < N; i++) {
        idx[i] = i;
    }
    sort(idx.begin(), idx.end(), [&](ll a, ll b){
        if(v[a].first != v[b].first) return v[a].first < v[b].first;
        return v[a].second > v[b].second;
    });
    ll minval = INF;
    ll minidx = -1;
    vector<ll> ans(N);
    for(auto tmp : idx) {
        if(v[tmp].second > minval) {
            ans[tmp] = minidx;
        } else {
            ans[tmp] = -2;
        }
        if(chmin(minval, v[tmp].second)) {
            minidx = tmp;
        }
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << ans[i] + 1;
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