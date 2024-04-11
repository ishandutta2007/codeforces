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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> bits(20);
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        for(int j = 0; j < 20; j++) {
            if(a & (1 << j)) bits[j]++;
        }
    }
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        ll tmp = 0;
        for(int j = 0; j < 20; j++) {
            if(bits[j] > 0) {
                bits[j]--;
                tmp += (1 << j);
            }
        }
        ans += tmp * tmp;
    }
    cout << ans << endl;
    return 0;
}