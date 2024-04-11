#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const ll mod = 1000000007;

void solve() {
    ll x, N;
    string S;
    cin >> x >> S;
    N = S.size();
    for(ll i = 1; i <= x; i++) {
        for(int timer = '1'; timer < S[i-1]; timer++) {
            for(int j = i; j < N; j++) {
                if(S.size() > x) break;
                S.push_back(S[j]);
            }
        }
        N += (N - i) * (S[i-1] - '1');
        N += 3 * mod;
        N %= mod;
        //cerr << S << " " << N << endl;
    }
    cout << N << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}