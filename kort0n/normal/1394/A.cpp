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
    ll N, D, M;
    cin >> N >> D >> M;
    vector<ll> high, low;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        if(a > M) high.push_back(a);
        else low.push_back(a);
    }
    sort(high.begin(), high.end(), greater<ll>());
    sort(low.begin(), low.end(), greater<ll>());
    vector<ll> highsum(1), lowsum(1);
    for(auto tmp : high) {
        ll val = highsum.back() + tmp;
        highsum.push_back(val);
    }
    for(auto tmp : low) {
        ll val = lowsum.back() + tmp;
        lowsum.push_back(val);
    }
    while(highsum.size() < N) {
        ll val = highsum.back();
        highsum.push_back(val);
    }
    while(lowsum.size() < N) {
        ll val = lowsum.back();
        lowsum.push_back(val);
    }
    ll ans = 0;
    for(ll h = 0; h <= N; h++) {
        ll l;
        if(h == 0) l = N;
        else l = N - (h - 1) * D - h;
        if(h < 0) continue;
        if(l < 0) continue;
        if(h >= highsum.size()) continue;
        if(l >= lowsum.size()) continue;
        //cerr << h << " " << l << " " << highsum.size() << " " << lowsum.size() << endl;
        chmax(ans, highsum[h] + lowsum[l]);
    }
    cout << ans << endl;
    return 0;
}