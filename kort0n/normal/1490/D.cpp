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
ll depth[105];
ll p[105];

void f(int l, int r, int d) {
    if(l == r) return;
    int m = l;
    for(int i = l; i < r; i++) {
        if(p[i] > p[m]) m = i;
    }
    depth[m] = d;
    f(l, m, d + 1);
    f(m + 1, r, d + 1);
}

void solve() {
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }
    f(0, N, 0);
    for(int i = 0; i < N; i++) cout << depth[i] << " ";
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