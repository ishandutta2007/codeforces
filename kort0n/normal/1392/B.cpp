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
vector<ll> a;
ll N, K;

void f() {
    ll d = -INF;
    for(auto tmp : a) {
        chmax(d, tmp);
    }
    for(int i = 0; i < N; i++) {
        a[i] = d - a[i];
    }
}

void solve() {
    cin >> N >> K;
    a.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }
    if(K > 1) {
        K -= 2;
        K %= 2;
        K += 2;
    }
    while(K--) f();
    for(auto tmp : a) cout << tmp << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}