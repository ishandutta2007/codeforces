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

vector<ll> f(ll N) {
    if(N == 4) {
        return {2, 1, 1};
    }
    if(N % 2 == 0) {
        auto ret = f(N / 2);
        for(auto &tmp : ret) tmp *= 2;
        return ret;
    }
    vector<ll> ret;
    ret.push_back(1);
    N--;
    ret.push_back(N/2);
    ret.push_back(N/2);
    return ret;
}

void solve() {
    ll N, K;
    cin >> N >> K;
    vector<ll> v;
    for(int i = 0; i < K - 3; i++) {
        N--;
        v.push_back(1);
    }
    auto tmp = f(N);
    for(auto val : tmp) v.push_back(val);
    for(int i = 0; i < K; i++) {
        if(i != 0) cout << " ";
        cout << v[i];
    }
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