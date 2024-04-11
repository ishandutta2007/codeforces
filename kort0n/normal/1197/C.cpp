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
ll a[305000];
vector<l_l> v;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 2; i <= N; i++) v.push_back({a[i] - a[i-1], i-1});
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i = 0; i < N - K ; i++) {
        ans += v[i].first;
    }
    cout << ans << endl;
    return 0;
}