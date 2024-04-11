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
ll N, K, L;
vector<ll> d;

bool f(ll s) {
    ll a = 0;
    for(ll i = s; i < N; i++) {
        if(d[i] - K > L) return false;
        if(d[i] <= L) return f(i + 1);
        a++;
        ll delta = L - (d[i] - K);
        ll minimum = K - delta;
        chmax(a, minimum);
        ll maximum = K + delta;
        //cerr << i << " " << a << " " << L << " " << delta << endl;
        if(maximum < a) return false;
    }
    return true;
}

void solve() {
    //cerr << "----------------" << endl;
    cin >> N >> K >> L;
    d.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> d[i];
        d[i] += K;
    }
    if(f(0)) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}