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

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> v;
    vector<l_l> a(M);
    for(int i = 0; i < M; i++) {
        cin >> a[i].second >> a[i].first;
        v.push_back(a[i].second);
    }
    sort(v.begin(), v.end(), greater<ll>());
    ll ans = 0;
    if(N <= v.size()) {
        for(int i = 0; i < N; i++) ans += v[i];
    }
    ll now = 0;
    ll idx = 0;
    sort(a.begin(), a.end(), greater<l_l>());
    for(int i = 0; i < a.size(); i++) {
        while(idx < v.size() and v[idx] > a[i].first) {
            now += v[idx];
            idx++;
        }
        ll tmpval = now;
        ll rest = N - idx;
        if(idx < v.size() and a[i].second <= v[idx]) {
            rest--;
            tmpval += a[i].second;
        }
        //cerr << i << " " << a[i].second << " " << a[i].first << " " << idx << " " << rest << " " << tmpval << endl;
        if(rest < 0) continue;
        tmpval += rest * a[i].first;
        //cerr << i << " " << a[i].second << " " << a[i].first << " " << idx << " " << rest << " " << tmpval << endl;
        chmax(ans, tmpval);
    }
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