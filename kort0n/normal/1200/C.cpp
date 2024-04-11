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
//const ll mod = 1000000007;
ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n, m, q;
    cin >> n >> m >> q;
    ll g = gcd(n, m);
    ll N = n /g;
    ll M = m / g;
    while(q--) {
        ll sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        ll S;
        if(sx == 1) {
            S = (sy + N - 1) / N;
        } else {
            S = (sy + M - 1) / M;
        }
        ll E;
        if(ex == 1) {
            E = (ey + N - 1) / N;
        } else {
            E = (ey + M - 1) / M;
        }
        if(E == S) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}