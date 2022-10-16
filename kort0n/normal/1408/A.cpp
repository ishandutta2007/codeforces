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
    vector<ll> a[3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < N; j++) {
            ll b;
            cin >> b;
            a[i].push_back(b);
        }
    }
    vector<ll> ans(N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < 3; j++) {
            if(i > 0 and ans[i-1] == a[j][i]) continue;
            if(i == N - 1 and ans[0] == a[j][i]) continue;
            ans[i] = a[j][i];
            break;
        }
    }
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}