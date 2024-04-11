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
ll ans[500][500];

void solve() {
    ll N, K;
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            ans[i][j] = 0;
        }
    }
    ll i = 0;
    ll j = 0;
    while(K--) {
        ans[i][j] = 1;
        i = (i + 1) % N;
        j = (j + 1) % N;
        if(i == 0) j = (j + 1) % N;
    }
    ll MR = 0;
    ll mR = INF;
    ll MC = 0;
    ll mC = INF;
    for(int h = 0; h < N; h++) {
        ll now = 0;
        for(int w = 0; w < N; w++) {
            now += ans[h][w];
        }
        chmax(MR, now);
        chmin(mR, now);
    }
    for(int h = 0; h < N; h++) {
        ll now = 0;
        for(int w = 0; w < N; w++) {
            now += ans[w][h];
        }
        chmax(MC, now);
        chmin(mC, now);
    }
    ll tmp = (MR - mR) * (MR - mR);
    tmp += (MC - mC) * (MC - mC);
    cout << tmp << endl;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}