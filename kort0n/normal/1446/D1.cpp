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
ll op(ll a, ll b) {
    return max(a, b);
}
ll e() {
    return -INF;
}
ll mapping(ll a, ll b) {
    return a + b;
}
ll composition(ll a, ll b) {
    return a + b;
}
ll id() {
    return 0;
}
ll num[201000];
ll ans = 0;
ll border = 0;
bool h(ll x) {
    return x < border;
}
ll N;
ll mode = 0;
vector<ll> a;
ll T[500000];
const ll offset = 250000;
void f(ll val) {
    //cerr << "---------" << val << "--------" << endl;
    for(int i = 0; i < 5e5; i++) T[i] = INF;
    T[offset] = -1;
    ll now = 0;
    for(ll i = 0; i < N; i++) {
        if(a[i] == val) now++;
        if(a[i] == mode) now--;
        chmin(T[offset+now], i);
        chmin(T[offset+now], T[offset+now-1]);
        chmax(ans, i - T[offset+now]);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    a.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
        num[a[i]]++;
    }
    for(ll i = 0; i < N; i++) {
        if(num[i] > num[mode]) mode = i;
    }
    for(int val = 0; val < 100; val++) {
        if(val == mode) continue;
        f(val);
    }
    cout << ans << endl;
    return 0;
}