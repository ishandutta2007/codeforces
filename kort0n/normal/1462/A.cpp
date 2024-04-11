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

void solve() {
    ll N;
    cin >> N;
    deque<ll> deq;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        deq.push_back(a);
    }
    ll p = 0;
    while(deq.size()) {
        if(p == 0) cout << deq.front() << " ", deq.pop_front();
        if(p == 1) cout << deq.back() << " ", deq.pop_back();
        p = 1 - p;
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