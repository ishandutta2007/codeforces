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
const ll mod = 998244353;
string S;
int N;
ll dp[2005][2005];
ll now[2005];
ll Next[2005];
ll ans = 0;
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S;
    N = S.size();
    S = "#" + S;
    dp[0][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= N; j++) {
            if(S[i] != '(') {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
            if(S[i] != ')') {
                dp[i][j+1] += dp[i-1][j];
                dp[i][j+1] %= mod;
            }
        }
        for(int j = 0; j <= N; j++) {
            //cerr << i << " " << j << " " << dp[i][j] << endl;
        }
    }
    now[0] = 1;
    for(int i = N; i >= 1; i--) {
        if(S[i] != '(') {
            ll sum = 0;
            for(int j = N + 1; j >= 1; j--) {
                sum += dp[i-1][j];
                sum %= mod;
                ans += sum * now[j - 1];
                ans %= mod;
                //cerr << i << " " << j << " " << sum << " " << now[j-1] << endl;
            }
        }
        for(int j = 0; j <= N; j++) Next[j] = 0;
        for(int j = 0; j <= N; j++) {
            if(S[i] != '(') {
                Next[j+1] += now[j];
                Next[j+1] %= mod;
            }
            if(S[i] != ')') {
                Next[j] += now[j];
                Next[j] %= mod;
            }
        }
        swap(Next, now);
        //cerr << i << " " <<ans << endl;
    }
    cout << ans << endl;
    return 0;
}