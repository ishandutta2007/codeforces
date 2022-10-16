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

void solve() {
    ll N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    vector<ll> v(N);
    ll before = -K-1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') before = i;
        if(i > before + K) v[i]++;
    }
    before = N + K;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == '1') before = i;
        if(i < before - K) v[i]++;
    }
    int ans = 0;
    before = -K-1;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') before = i;
        if(i > before + K and v[i] == 2) {
            ans++;
            before = i;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}