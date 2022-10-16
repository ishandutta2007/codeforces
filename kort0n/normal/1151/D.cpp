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
    vector<l_l> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end(), [](l_l a, l_l b){
        return a.first - a.second > b.first - b.second;
    });
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ans += v[i].first * i;
        ans += v[i].second * (N - 1 - i);
    }
    cout << ans << endl;
    return 0;
}