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
ll f(ll x) {
    if(x <= 9) return x;
    return (x % 10) + f(x / 10);
}

ll dp[155];
ll beki[19];
void solve() {
    ll N, K;
    cin >> N >> K;
    for(int i = 0; i <= N; i++) {
        dp[i] = INF;
    }
    vector<ll> v;
    for(int i = 0; i <= 17; i++) {
        for(int j = 1; j <= 10; j++) {
            v.push_back(beki[i+1]-j);
        }
        sort(v.begin(), v.end());
        vector<ll> w;
        for(auto val : v) {
            ll tmp = 0;
            for(int i = 0; i <= K; i++) {
                tmp += f(val + i);
            }
            //cerr << tmp << " " << val << endl;
            if(tmp > N) continue;
            if(chmin(dp[tmp], val)) {
                if(tmp == N) {
                    cout << val << endl;
                    return;
                }
                for(int j = 1; j <= 9; j++) {
                    w.push_back(j*beki[i+1]+val);
                }
            }
        }
        swap(w, v);
    }
    cout << -1 << endl;
}

int main() {
    beki[0] = 1;
    for(ll i = 1; i <= 18; i++) {
        beki[i] = beki[i-1] * 10;
    }
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}