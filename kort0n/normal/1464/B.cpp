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
string S;
ll x, y;
ll ans = INF;
ll N;

void solve() {
    N = S.size();
    vector<ll> one(N+1), zero(N+1), q(N+1);
    ll tmpans = 0;
    for(int i = 0; i < N; i++) {
        one[i+1] = one[i];
        zero[i+1] = zero[i];
        q[i+1] = q[i];
        if(S[i] == '0') zero[i+1]++;
        if(S[i] == '1') one[i+1]++;
        if(S[i] == '?') q[i+1]++;
        if(S[i] == '1') {
            tmpans += (zero[i] + q[i])* x;
        } else {
            tmpans += one[i] * y;
        }
    }
    chmin(ans, tmpans);
    //cerr << "-1 " << tmpans << endl;
    for(int i = 0; i < N; i++) {
        if(S[i] != '?') continue;
        tmpans += zero[i] * x;
        tmpans -= (one[i] + q[i]) * y;
        tmpans += ((zero[N] - zero[i+1]) + (q[N] - q[i+1])) * y;
        tmpans -= (one[N] - one[i+1]) * x;
        chmin(ans, tmpans);
        //cerr << i << " " << tmpans << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> S >> x >> y;
    solve();
    reverse(S.begin(), S.end());
    swap(x, y);
    solve();
    cout << ans << endl;
    return 0;
}