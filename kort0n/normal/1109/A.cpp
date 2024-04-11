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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
ll N;

int main() {
    cin >> N;
    vector<ll> a(N);
    vector<ll> sum(N+1);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        sum[i+1] = sum[i] ^ a[i];
    }
    //for(auto val : sum) cerr << val << " ";
    ll ans = 0;
    for(int d = 0; d <= 1; d++) {
        map<ll, ll> mp;
        for(ll i = d; i <= N; i += 2) {
            ans += mp[sum[i]];
            mp[sum[i]]++;
        }
    }
    cout << ans << endl;
    return 0;
}