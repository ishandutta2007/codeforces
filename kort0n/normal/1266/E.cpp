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

ll a[200100];
ll num[201000];
ll Q;
ll N;
ll ans;
map<l_l, ll> mp;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> a[i];
        ans += a[i];
    }
    cin >> Q;
    while(Q--) {
        ll s, t, u;
        cin >> s >> t >> u;
        if(mp[{s, t}] != 0) {
            ll idx = mp[{s, t}];
            ans += min(a[idx], num[idx]);
            num[idx]--;
            ans -= min(a[idx], num[idx]);
            mp[{s, t}] = 0;
        }
        mp[{s, t}] = u;
        ans += min(a[u], num[u]);
        num[u]++;
        ans -= min(a[u], num[u]);
        cout << ans << endl;
    }
    return 0;
}