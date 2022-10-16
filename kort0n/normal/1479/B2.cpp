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
ll dp[201000];
map<ll, ll> mp;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    a.erase(unique(a.begin(), a.end()), a.end());
    N = a.size();
    for(int i = 0; i < N; i++) {
        dp[i+1] = dp[i] + 1;
        if(mp.count(a[i])) {
            chmin(dp[i+1], mp[a[i]] + i - 1);
        }
        ll c = a[i];
        if(mp.count(c) == 0) {
            mp[c] = INF;
        }
        chmin(mp[c], dp[i+1] - i);
        if(i != 0) {
            c = a[i-1];
        }
        if(mp.count(c) == 0) {
            mp[c] = INF;
        }
        chmin(mp[c], dp[i+1] - i);
    }
    cout << dp[N] << endl;
    return 0;
}