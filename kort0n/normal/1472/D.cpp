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
void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    vector<ll> b(2);
    for(int i = 0; i < N; i++) {
        if(i % 2 == a[i] % 2) {
            b[i%2] += a[i];
        }
    }
    string ans;
    if(b[0] > b[1]) ans = "Alice";
    if(b[0] == b[1]) ans = "Tie";
    if(b[0] < b[1]) ans = "Bob";
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}