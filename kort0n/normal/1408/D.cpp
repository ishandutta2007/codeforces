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
ll a[5000], b[5000], c[5000], d[5000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 0; i < M; i++) {
        cin >> c[i] >> d[i];
    }
    vector<l_l> v;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(a[i] > c[j]) continue;
            if(b[i] > d[j]) continue;
            v.push_back({c[j] - a[i] + 1, d[j] - b[i] + 1});
        }
    }
    sort(v.begin(), v.end(), greater<l_l>());
    if(v.empty()) {
        cout << 0 << endl;
        return 0;
    }
    ll bdist = 0;
    ll ans = INF;
    for(int i = 0; i < v.size(); i++) {
        //cout << v[i].first << ", " << v[i].second << endl;
        chmin(ans, bdist + v[i].first);
        chmax(bdist, v[i].second);
    }
    chmin(ans, bdist);
    cout << ans << endl;
    return 0;
}