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
ll n, k;
ll a[100050];
map<vector<l_l>, ll> mp;

vector<l_l> f(ll val) {
    vector<l_l> ret;
    for(ll i = 2; i * i <= val; i++) {
        ll now = 0;
        while(val % i == 0) {
            now++;
            val /= i;
        }
        now %= k;
        if(now != 0) {
            ret.push_back({i, now});
        }
    }
    if(val != 1) {
        ret.push_back({val, 1});
    }
    return ret;
}

vector<l_l> g(vector<l_l> v) {
    for(int i = 0; i < v.size(); i++) {
        v[i].second = k - v[i].second;
    }
    return v;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    ll ans = 0;
    for(ll i = 1; i <= n; i++) {
        cin >> a[i];
        vector<l_l> v = f(a[i]);
        //for(auto val : v) cerr << val.first << " " << val.second << endl;
        vector<l_l> w = g(v);
        ans += mp[w];
        mp[v]++;
    }
    cout << ans << endl;
    return 0;
}