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
    vector<ll> v(3);
    for(int i = 0; i < 3; i++) cin >> v[i];
    ll d;
    cin >> d;
    sort(v.begin(), v.end());
    ll ans = 0;
    ans += max((ll)0, d - (v[1] - v[0]));
    ans += max((ll)0, d - (v[2] - v[1]));
    cout << ans << endl;
    return 0;
}