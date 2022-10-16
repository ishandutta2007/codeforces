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
ll ans;
ll N;
string S;

void f() {
    ll ret = 0;
    string LR = "LR";
    for(int i = 0; i < N; i++) {
        if(LR[(i%2)] != S[i]) ret++;
    }
    chmin(ans, ret);
}

ll dp[201000];
vector<string> A;

void g() {
    for(int i = 0; i <= N; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for(int i = 0; i < N; i++) {
        for(auto s : A) {
            if(i + s.size() > N) continue;
            ll tmp = dp[i];
            for(int j = 0; j < s.size(); j++) {
                if(s[j] != S[i+j]) tmp++;
            }
            chmin(dp[i+s.size()], tmp);
        }
    }
    chmin(ans, dp[N]);
}


void solve() {
    cin >> N >> S;
    ans = INF;
    for(int i = 0; i < 5; i++) {
        if(N % 2 == 0) f();
        g();
        char c = S[0];
        S.push_back(c);
        S.erase(S.begin());
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    A.push_back("RL");
    A.push_back("RRL");
    A.push_back("RLL");
    A.push_back("RRLL");
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}