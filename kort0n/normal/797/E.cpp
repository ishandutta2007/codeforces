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
int dp[500][100000];
int a[100000];
int main() {
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 1; i < 500; i++) {
        for(int j = N - 1; j >= 0; j--) {
            int to = j + a[j] + i;
            if(to >= N) dp[i][j] = 1;
            else dp[i][j] = dp[i][to] + 1;
        }
    }
    int Q;
    cin >> Q;
    while(Q--) {
        int p, b;
        cin >> p >> b;
        p--;
        if(b < 500) {
            cout << dp[b][p] << endl;
        } else {
            int ans = 0;
            while(p < N) {
                ans++;
                p = p + a[p] + b;
            }
            cout << ans << endl;
        }
    }
    return 0;
}