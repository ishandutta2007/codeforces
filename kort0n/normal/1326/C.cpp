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
ll N, K;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> K;
    vector<ll> p(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    ll ans1 = 0;
    for(ll i = 0; i < K; i++) {
        ans1 += N - i;
    }
    cout << ans1 << " ";
    ll ans = 1;
    ll before = -1;
    for(int i = 0; i < N; i++) {
        if(p[i] > N - K) {
            if(before != -1) {
                ans *= (i - before);
                ans %= mod;
            }
            before = i;
        }
    }
    cout << ans << endl;
    return 0;
}