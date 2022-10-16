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
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, K;
    cin >> N >> K;
    vector<ll> v(N);
    for(int i = 0; i < N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 0; i + K < N; i++) {
        if(v[i] == v[i+K-1]) {
            cout << 0 << endl;
            return 0;
        }
    }
    vector<ll> sum(N+1);
    for(int i = 0; i < N; i++) {
        sum[i+1] = sum[i] + v[i];
    }
    ll ans = 1e18;
    ll now = 0;
    ll num = 0;
    for(int i = K; i < N; i++) {
        if(v[i] == v[K-1]) num++;
    }
    now = sum[K-1] - v[K-1] * (K - 1);
    now *= -1;
    now -= num;
    chmin(ans, now);
    now = 0;
    num = 0;
    for(int i = 0; i < N - K; i++) {
        if(v[N-K] == v[i]) num++;
    }
    now = sum[N] - sum[N-K+1] - v[N-K] * (K-1);
    now -= num;
    chmin(ans, now);
    ll idx = N / 2;
    now = 0;
    for(int i = 0; i < N; i++) {
        now += abs(v[i] - v[idx]);
    }
    now -= N - K;
    chmin(ans, now);
    cout << ans << endl;
    return 0;
}