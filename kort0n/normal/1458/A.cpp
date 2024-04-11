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
vector<ll> a, b;
ll N, M;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> M;
    a.resize(N);
    b.resize(M);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for(int j = 0; j < M; j++) {
        cin >> b[j];
    }
    ll g = 0;
    for(int i = 0; i + 1 < N; i++) {
        g = __gcd(g, abs(a[i] - a[i+1]));
    }
    for(int i = 0; i < M; i++) {
        ll ans = __gcd(g, a[0] + b[i]);
        if(i != 0) cout << " ";
        cout << ans;
    }
    cout << endl;
    return 0;
}