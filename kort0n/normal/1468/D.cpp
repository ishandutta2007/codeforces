#include "bits/stdc++.h"
using namespace std;
using ll = long long;

void solve() {
    ll N, M, a, b;
    cin >> N >> M >> a >> b;
    ll ng = min(M + 1, abs(a - b));
    ll ok = 0;
    ll T = 0;
    if(a < b) T = b - 1;
    else T = (N - b);
    vector<ll> v(M);
    //cerr << T << endl;
    for(int i = 0; i < M; i++) cin >> v[i];
    sort(v.begin(), v.end());
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        bool can = true;
        for(ll i = 0; i < mid; i++) {
            if(v[mid-1-i] + i + 1 > T) can = false;
        }
        if(can) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}