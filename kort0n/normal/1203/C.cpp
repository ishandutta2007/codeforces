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
ll N;
ll a[405000];
ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

vector<ll> f(ll P) {
    vector<ll> ret;
    for(ll i = 2; i * i <= P; i++) {
        if(P % i != 0) continue;
        ret.push_back(0);
        while(P % i == 0) {
            P /= i;
            ret.back()++;
        }
    }
    if(P != 1) ret.push_back(1);
    return ret;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    ll g = 0;
    for(int i = 1; i <= N; i++) g = gcd(g, a[i]);
    vector<ll> P = f(g);
    ll ans = 1;
    for(int i = 0; i < P.size(); i++) ans *= P[i] + 1;
    cout << ans << endl;
    return 0;
}