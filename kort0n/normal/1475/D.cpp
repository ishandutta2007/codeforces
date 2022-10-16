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
ll a[201000], b[201000];
void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> one, two;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> b[i];
        if(b[i] == 1) one.push_back(a[i]);
        else two.push_back(a[i]);
    }
    sort(one.begin(), one.end(), greater<ll>());
    sort(two.begin(), two.end(), greater<ll>());
    ll ans = INF;
    vector<ll> onesum = {0};
    vector<ll> twosum = {0};
    for(auto tmp : one) {
        ll val = onesum.back() + tmp;
        onesum.push_back(val);
    }
    for(auto tmp : two) {
        ll val = twosum.back() + tmp;
        twosum.push_back(val);
    }
    for(int i = 0; i < twosum.size(); i++) {
        ll rest = M - twosum[i];
        auto itr = lower_bound(onesum.begin(), onesum.end(), rest);
        if(itr == onesum.end()) continue;
        ll tmpans = 2 * i + (itr - onesum.begin());
        chmin(ans, tmpans);
    }
    if(ans == INF) ans = -1;
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