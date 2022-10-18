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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, X;
    cin >> N >> X;
    vector<ll> d(N);
    for(int i = 0; i < N; i++) cin >> d[i];
    for(int i = 0; i < N; i++) {
        ll tmp = d[i];
        d.push_back(tmp);
    }
    vector<ll> sum(2 * N + 1);
    vector<ll> sumd(2 * N + 1);
    for(int i = 0; i < 2 * N; i++) {
        sum[i+1] = sum[i] + (d[i] + 1) * d[i] / 2;
        sumd[i+1] = sumd[i] + d[i];
    }
    ll ans = 0;
    for(int i = N + 1; i <= 2 * N; i++) {
        int ok = 0;
        int ng = i;
        while(abs(ok - ng) > 1) {
            int mid = (ok + ng) / 2;
            if(sumd[i] - sumd[mid] >= X) ok = mid;
            else ng = mid;
        }
        //cerr << i << " " << ok << endl;
        ll tmp = sum[i] - sum[ok];
        ll rest = sumd[i] - sumd[ok] - X;
        tmp -= (rest) * (rest + 1) / 2;
        chmax(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}