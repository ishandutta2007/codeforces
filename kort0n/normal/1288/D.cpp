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
//const ll mod = 1000000007;
ll N, M;
ll dp[1 << 8];
ll a[305000][10];

void f(int border) {
    for(int i = 0; i < (1 << M); i++) {
        dp[i] = -1;
    }
    for(int i = 0; i < N; i++) {
        int bits = 0;
        for(int j = 0; j < M; j++) {
            if(a[i][j] >= border) {
                bits |= (1 << j);
            }
        }
        dp[bits] = i;
    }
    for(int i = (1 << M) - 1; i >= 0; i--) {
        for(int j = 0; j < M; j++) {
            if(dp[i] != -1) break;
            dp[i] = dp[i | (1 << j)];
        }
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> a[i][j];
        }
    }
    ll ok = 0;
    ll ng = 1e9 + 1;
    while(ng - ok > 1) {
        ll mid = (ng + ok) / 2;
        f(mid);
        for(int i = 0; i < (1 << M); i++) {
            if(dp[i] == -1) continue;
            int j = (1 << M) - 1;
            j ^= i;
            if(dp[j] == -1) continue;
            ok = mid;
        }
        if(ok != mid) ng = mid;
    }
    f(ok);
    for(int i = 0; i < (1 << M); i++) {
        if(dp[i] == -1) continue;
        int j = (1 << M) - 1;
        j ^= i;
        if(dp[j] == -1) continue;
        cout << dp[i]+1 << " " << dp[j]+1 << endl;
        return 0;
    }
    return 0;
}