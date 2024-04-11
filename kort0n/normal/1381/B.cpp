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
typedef bitset<2005> BITS;
BITS dp[2005];
BITS zero;

void solve() {
    ll N;
    cin >> N;
    vector<ll> p(2 * N);
    for(int i = 0; i < 2 * N; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<ll> v;
    ll now = 1;
    ll before = p[0];
    for(int i = 1; i < 2 * N; i++) {
        if(p[i] < before) {
            now++;
            continue;
        } else {
            v.push_back(now);
            now = 1;
            before = p[i];
        }
    }
    v.push_back(now);
    for(int i = 0; i <= v.size(); i++) {
        dp[i] = zero;
    }
    dp[0][0] = true;
    //cerr << "----" << endl;
    for(int i = 0; i < v.size(); i++) {
        //cerr << v[i] << endl;
        dp[i+1] = dp[i] | (dp[i] << v[i]);
    }
    string ans = "NO";
    if(dp[v.size()][N]) ans = "YES";
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i <= 2000; i++) {
        zero[i] = false;
    }
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}