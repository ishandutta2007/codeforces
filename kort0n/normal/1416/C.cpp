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
ll ansx, ansb;

ll g(vector<ll> v) {
    ll ret = 0;
    ll num = 0;
    for(auto c : v) {
        if(c == 1) num++;
        else ret += num;
    }
    return ret;
}

void f(ll d, vector<vector<ll>> a) {
    if(d == -1) return;
    ll retx = -1;
    ll retb = INF;
    for(ll x = 0; x <= 1; x++) {
        ll tmpb = 0;
        for(auto v : a) {
            for(auto &e : v) {
                e = (e >> d);
                e &= 1LL;
                e ^= x;
            }
            tmpb += g(v);
        }
        if(chmin(retb, tmpb)) {
            retx = x;
        }
    }
    ansx += (1LL << d) * retx;
    ansb += retb;
    vector<vector<ll>> b;
    for(auto v : a) {
        vector<ll> u[2];
        for(auto e : v) {
            u[(e >> d) & 1LL].push_back(e);
        }
        for(auto tmp : u) {
            if(!tmp.empty()) b.push_back(tmp);
        }
    }
    f(d - 1, b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    f(30, {a});
    cout << ansb << " " << ansx << endl;
    return 0;
}