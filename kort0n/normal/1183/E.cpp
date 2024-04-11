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
//const ll mod = 1000000007;
ll dp[105][105];
ll n;
ll k;
string S;
map<char, int> Last;
ll num[105];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k >> S;
    S = "#" + S;
    dp[0][0] = 1;
    for(int index = 1; index < S.size(); index++) {
        //cerr << S[index] << " " << Last[S[index]] << endl;
        for(int num = 1; num <= 100; num++) {
            for(int j = Last[S[index]]; j < index; j++) {
                dp[index][num] += dp[j][num-1];
                chmin(dp[index][num], (ll)1e13);
            }
            //cerr << index << " " << num << " " << dp[index][num] << endl;
        }
        Last[S[index]] = index;
    }
    for(int index = 0; index < S.size(); index++) {
        for(int i = 0; i <= 100; i++) {
            num[i] += dp[index][i];
            chmin(num[i], (ll)1e13);
        }
    }
    //for(int i = 0; i <= 100; i++) cerr << i << " " << num[i] << endl;
    ll rest = k;
    ll ans = 0;
    for(int val = 100; val >= 0; val--) {
        ll nownum = min(rest, num[val]);
        rest -= nownum;
        ans += nownum * (n - val);
    }
    if(rest > 0) ans = -1;
    cout << ans << endl;
    return 0;
}