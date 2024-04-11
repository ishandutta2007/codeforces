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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    while(n) {
        if(n % k == 0) {
            n /= k;
            ans++;
            continue;
        }
        ll NEW = n / k;
        ans += n - NEW * k;
        n = NEW * k;
    }
    cout << ans << endl;
    }
    return 0;
}