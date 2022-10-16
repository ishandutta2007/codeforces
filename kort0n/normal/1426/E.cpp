#include <bits/stdc++.h>
//#include <atcoder/all>
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
ll ans[2];
ll a[3];
ll b[3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    for(int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    for(int i = 0; i < 3; i++) {
        ans[1] += min(a[i], b[(i+1)%3]);
    }
    for(int i = 0; i < 3; i++) {
        ll tmp = a[i] + b[(i+1)%3] - N;
        chmax(ans[0], tmp);
    }
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}