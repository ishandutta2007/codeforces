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
const ll mod = 1000000007;
ll N;
string S;
ll K;
ll beki[301000];
ll num[4][301000];
string T = "abc?";
ll ans;

int main() {
    beki[0] = 1;
    for(ll i = 1; i <= 3e5; i++) {
        beki[i] = beki[i-1] * 3 % mod;
    }
    cin >> N;
    cin >> S;
    for(auto c : S) {
        if(c == '?') K++;
    }
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < N; j++) {
            num[i][j+1] = num[i][j];
            if(S[j] == T[i]) num[i][j+1]++;
        }
    }
    for(int i = 0; i < N; i++) {
        if(S[i] == 'a') continue;
        if(S[i] == 'c') continue;
        ll nowK = K;
        if(S[i] == '?') nowK--;
        ll beforea = num[0][i];
        ll befored = num[3][i];
        ll afterc = num[2][N] - num[2][i+1];
        ll afterd = num[3][N] - num[3][i+1];
        //cerr << i << " " << beforea << " " << befored << " " << afterc << " " << afterd << endl;
        ll tmp;
        tmp = beforea * afterc % mod;
        if(nowK >= 0) tmp *= beki[nowK];
        ans += tmp;
        ans %= mod;
        tmp = befored * afterc % mod;
        if(nowK >= 1) tmp *= beki[nowK-1];
        ans += tmp;
        ans %= mod;
        tmp = beforea * afterd % mod;
        if(nowK >= 1) tmp *= beki[nowK-1];
        ans += tmp;
        ans %= mod;
        tmp = befored * afterd % mod;
        if(nowK >= 2) tmp *= beki[nowK-2];
        ans += tmp;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}