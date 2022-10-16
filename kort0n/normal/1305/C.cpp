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
ll mod;
ll N, M;
vector<ll> a;
ll beki(ll a, ll b) {
    a %= mod;
    if(b == 0) return 1 % mod;
    ll ret = beki(a, b / 2);
    ret = ret * ret % mod;
    if(b & 1) ret = ret * a % mod;
    return ret;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    if(N > M) {
        cout << 0 << endl;
        return 0;
    }
    mod = M;
    a.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<ll> num(M);
    ll ans = 1;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(num[j] == 0) continue;
            ans *= beki(a[i] - j + mod, num[j]);
            ans %= mod;
        }
        num[a[i] % M]++;
    }
    cout << ans << endl;
    return 0;
}