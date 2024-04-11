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
int N;
int a[100], b[100];
int c[100], d[100];
int sum = 0;
int dp[101][200001];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        d[i] = b[i];
        c[i] = 2 * a[i] - d[i];
        //cerr << c[i] << " " << d[i] << endl;
        sum += d[i];
    }
    //cerr << sum << endl;
    for(int i = 0; i <= 100; i++) {
        for(int j = 0; j <= 2e5; j++) {
            dp[i][j] = -1e9;
        }
    }
    dp[0][sum] = 0;
    for(int i = 0; i < N; i++) {
        for(int j = i; j >= 0; j--) {
            for(int k = 0; k <= sum; k++) {
                int delta = min(k, c[i]);
                chmax(dp[j+1][k-delta], dp[j][k] + delta + d[i]);
            }
        }
    }
    for(int i = 1; i <= N; i++) {
        double ans = 0;
        for(int j = 0; j <= sum; j++) {
            chmax(ans, 0.5 * dp[i][j]);
        }
        if(i != 1) cout << " ";
        cout << fixed << setprecision(60) << ans;
    }
    cout << endl;
    return 0;
}