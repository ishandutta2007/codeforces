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
    ll a, b, c;
    cin >> a >> b >> c;
    ll ans1 = 2 * c + 2 * min(a, b);
    if(a > b) ans1++;
    ll ans2;
    if(b == 0) ans2 = 0;
    else {
        ans2 = 1;
        b--;
        ans2 += 2 * c;
        ans2 += min(a, b) * 2;
        if(a > b) ans2++;
    }
    cout << max(ans1, ans2) << endl;
    return 0;
}