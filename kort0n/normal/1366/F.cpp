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
const ll mod = 1000000007;
ll dp[2050][2050];
ll N, M, Q;
//vector<l_l> paths[2000];
ll u[2000], v[2000], c[2000];
ll ans = 0;
ll maxi[1000010], mini[1000010];
ll val[1000100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M >> Q;
    Q -= M;
    vector<ll> w;
    for(int i = 0; i < M; i++) {
        cin >> u[i] >> v[i] >> c[i];
        w.push_back(c[i]);
        u[i]--;
        v[i]--;
    }
    sort(w.begin(), w.end());
    w.erase(unique(w.begin(), w.end()), w.end());
    for(int i = 0; i <= M; i++) {
        for(int j = 0; j <= M; j++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j++) {
            chmax(dp[i+1][u[j]], dp[i][v[j]] + c[j]);
            chmax(dp[i+1][v[j]], dp[i][u[j]] + c[j]);
        }
    }
    for(int i = 1; i <= M; i++) {
        ll tmp = 0;
        for(ll j = 0; j < N; j++) {
            chmax(tmp, dp[i][j]);
        }
        ans += tmp;
        ans %= mod;
    }
    for(int i = 0; i < M; i++) {
        for(int j = 0; j <= M; j++) {
            ll tmp = dp[j][u[i]];
            chmax(tmp, dp[j][v[i]]);
            tmp += (M - j) * c[i];
            chmax(val[c[i]], tmp);
        }
    }
    for(int i = 0; i <= 1e6; i++) {
        if(val[i] != 0) {
            //cerr << i << " " << val[i] << endl;
        }
    }
    for(int i = 0; i <= 1e6; i++) {
        mini[i] = 1;
        maxi[i] = Q + 1;
    }
    for(int i = 0; i < w.size(); i++) {
        for(int j = i + 1; j < w.size(); j++) {
            ll ok = Q + 1;
            ll ng = 0;
            while(abs(ok - ng) > 1) {
                ll mid = (ok + ng) / 2;
                if(mid * w[j] + val[w[j]] >= mid * w[i] + val[w[i]]) {
                    ok = mid;
                } else {
                    ng = mid;
                }
            }
            chmin(maxi[w[i]], ok);
            chmax(mini[w[j]], ok);
        }
    }
    for(auto tmp : w) {
        ll delta = maxi[tmp] - mini[tmp];
        if(delta <= 0) continue;
        //cerr << tmp << " " << mini[tmp] << " " << maxi[tmp] << endl;
        ll lval = val[tmp] + tmp * mini[tmp];
        ll rval = val[tmp] + tmp * (maxi[tmp] - 1);
        ll tmp2 = lval + rval;
        tmp2 %= mod;
        tmp2 *= delta;
        tmp2 %= mod;
        tmp2 *= (mod + 1) / 2;
        tmp2 %= mod;
        ans += tmp2;
        ans %= mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}