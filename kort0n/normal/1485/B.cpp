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
ll N, Q, K;
ll A[105000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q >> K;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for(int q = 0; q < Q; q++) {
        ll l, r;
        cin >> l >> r;
        l--;
        r--;
        ll ans = 0;
        ans += A[l] - 1;
        ans += K - A[r];
        ans += ((A[r] - A[l]) - (r - l)) * 2;
        cout << ans << endl;
    }
    return 0;
}