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
ll a[301000];
ll N, M;

bool f(ll mid) {
    ll Last = 0;
    for(int i = 0; i < N; i++) {
        ll nxt = INF;
        if(a[i] >= Last) chmin(nxt, a[i]);
        if(a[i] <= Last and Last <= a[i] + mid) chmin(nxt, Last);
        if(a[i] + mid >= M and a[i] + mid - M >= Last) chmin(nxt, Last);
        if(nxt == INF) return false;
        Last = nxt;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> a[i];
    ll ok = M + 1;
    ll ng = -1;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}