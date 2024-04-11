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
ll u, v;
ll ans[3];

bool Zero() {
    if(u == 0 and v == 0) {
        cout << 0 << endl;
        return true;
    }
    return false;
}

bool One() {
    if(u == v) {
        cout << 1 << endl;
        cout << u << endl;
        return true;
    }
    return false;
}

bool Two() {
    if(u < 0) return false;
    ans[0] = 0;
    ans[1] = 0;
    vector<ll> V;
    ll sum = 0;
    vector<ll> W;
    for(ll bits = 0; bits < 60; bits++) {
        if(u & (1LL << bits)) {
            //ans[0] |= (1LL << bits);
            W.push_back(bits);
            sum += (1LL << bits);
        } else {
            V.push_back(bits);
        }
    }
    reverse(V.begin(), V.end());
    for(auto d : V) {
        if(sum + 2 * (1LL << d) <= v) {
            sum += 2 * (1LL << d);
            //ans[0] |= (1LL << d);
            //ans[1] |= (1LL << d);
            W.push_back(d);
            W.push_back(d);
        }
    }
    for(int i = 0; i < W.size(); i++) {
        ans[i%2] |= (1LL << W[i]);
    }
    return sum == v and ans[0] > 0 and ans[1] > 0;
}

bool Three() {
    if(u < 0) return false;
    ans[0] = 0;
    ans[1] = 0;
    ans[2] = 0;
    vector<ll> V;
    vector<ll> W;
    ll sum = 0;
    for(ll bits = 0; bits < 60; bits++) {
        if(u & (1LL << bits)) {
            //ans[2] |= (1 << bits);
            W.push_back(bits);
            sum += (1LL << bits);
            V.push_back(bits);
        } else {
            V.push_back(bits);
        }
    }
    reverse(V.begin(), V.end());
    for(auto d : V) {
        if(sum + 2 * (1LL << d) <= v) {
            sum += 2 * (1LL << d);
            //ans[0] |= (1 << d);
            //ans[1] |= (1 << d);
            W.push_back(d);
            W.push_back(d);
        }
    }
    sort(W.begin(), W.end());
    for(int i = 0; i < W.size(); i++) {
        assert(!(ans[i%3] & (1LL << W[i])));
        ans[i%3] |= (1LL << W[i]);
    }
    return sum == v and ans[0] > 0 and ans[1] > 0 and ans[2] > 0;
}

int main() {
    cin >> u >> v;
    if(u % 2 != v % 2) {
        cout << -1 << endl;
        return 0;
    }
    if(u > v) {
        cout << -1 << endl;
        return 0;
    }
    if(Zero()) return 0;
    if(One()) return 0;
    if(Two()) {
        cout << 2 << endl;
        cout << ans[0] << " " << ans[1] << endl;
        assert(ans[0] + ans[1] == v);
        assert((ans[0] ^ ans[1]) == u);
        return 0;
    }
    if(Three()) {
        cout << 3 << endl;
        cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
        assert(ans[0] + ans[1] + ans[2] == v);
        assert((ans[0] ^ ans[1] ^ ans[2]) == u);
        return 0;
    }
    for(int i = 0; i <= 1e9; i++) {
        cout << i << endl;
    }
    cout << -1 << endl;
    return 0;
}