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
vector<ll> a, b;
ll dp[200500];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    a.resize(n);
    b.resize(m + 1);
    b[0] = 0;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 1; i <= m; i++) cin >> b[i];
    dp[0] = 0;
    for(int i = 1; i <= m; i++) {
        dp[i] = dp[i-1] + 1;
        auto itr = upper_bound(a.begin(), a.end(), b[i] - ta);
        chmin(dp[i], (ll)distance(a.begin(), itr));
        //cerr << i << " "<< dp[i] << endl;
    }
    if(dp[m] <= k) {
        cout << -1 << endl;
        return 0;
    }
    int ok = 0;
    int ng = m;
    while(ng - ok > 1) {
        int mid = (ok + ng) / 2;
        if(dp[mid] > k) ng = mid;
        else ok = mid;
    }
    cerr << ok + 1 << endl;
    cout << b[ok + 1] + tb << endl;
    return 0;
}