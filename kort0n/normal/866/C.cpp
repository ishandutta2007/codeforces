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
long double dp[55][6000];
ll F[55], S[55], P[55];
int N, R;

void f(long double reset) {
    for(int i = 0; i < 6000; i++) {
        if(i <= R) dp[N][i] = 0;
        else dp[N][i] = reset;
    }
    for(int i = N - 1; i >= 0; i--) {
        for(int j = 0; j <= R; j++) {
            long double tmp = F[i] + dp[i+1][j+F[i]];
            if(j+F[i] > R) tmp = F[i] + reset;
            tmp *= P[i];
            tmp /= 100;
            long double tmp2 = S[i] + dp[i+1][j+S[i]];
            if(j + S[i] > R) tmp2 = S[i] + reset;
            tmp2 *= (100 - P[i]);
            tmp2 /= 100;
            dp[i][j] = tmp + tmp2;
            if(i > 0) {
                chmin(dp[i][j], reset);
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> R;
    for(int i = 0; i < N; i++) {
        cin >> F[i] >> S[i] >> P[i];
    }
    long double ok = 1e18;
    long double ng = 0;
    for(int _ = 0; _ <= 300; _++) {
        long double mid = (ok + ng) / 2;
        f(mid);
        if(dp[0][0] <= mid) ok = mid;
        else ng = mid;
    }
    cout << fixed << setprecision(40) << ok << endl;
    return 0;
}