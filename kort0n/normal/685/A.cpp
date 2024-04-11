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
ll a[2];
ll num[2][1<<10];
ll sum = 0;

int main() {
    for(int i = 0; i < 2; i++) {
        cin >> a[i];
        ll d = 1;
        ll factor = 1;
        while(a[i] > factor * 7) {
            factor *= 7;
            d++;
        }
        sum += d;
        if(sum > 7) continue;
        for(ll j = 0; j < a[i]; j++) {
            int bits = 0;
            ll copy = j;
            for(ll t = 0; t < d; t++) {
                bits |= 1 << (copy % 7);
                copy /= 7;
            }
            if(__builtin_popcount(bits) != d) continue;
            num[i][bits]++;
        }
    }
    ll ans = 0;
    for(ll i = 0; i < (1 << 10); i++) {
        for(ll j = 0; j < (1 << 10); j++) {
            if(i & j) continue;
            ans += num[0][i] * num[1][j];
        }
    }
    cout << ans << endl;
    return 0;
}