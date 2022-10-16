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
const ll mod = 998244353;
ll k[1050000];
vector<ll> inv[1050000];

ll beki(ll a, ll b){
    ll ret = 1 % mod;
    a %= mod;
    while(b) {
        if(b & 1LL) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> k[i];
        for(int j = 0; j < k[i]; j++) {
            ll a;
            cin >> a;
            a--;
            inv[a].push_back(i);
        }
    }
    ll ans = 0;
    for(int i = 0; i <= 1e6; i++) {
        if(inv[i].empty()) continue;
        ll tmp = 0;
        for(auto c : inv[i]) {
            tmp += beki(k[c], mod - 2);
        }
        tmp %= mod;
        tmp *= beki(N, mod - 2);
        tmp %= mod;
        tmp *= N - inv[i].size();
        tmp %= mod;
        tmp *= beki(N, mod - 2);
        tmp %= mod;
        ans += tmp;
    }
    ans %= mod;
    cout << (1 - ans + mod) % mod << endl;
    return 0;
}