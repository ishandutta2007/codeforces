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

void solve() {
    ll N;
    cin >> N;
    deque<ll> deq;
    for(int i = 0; i < N; i++) {
        ll a;
        cin >> a;
        deq.push_back(a);
    }
    ll a = 0;
    ll b = 0;
    ll t = 0;
    ll turns = 1;
    int previous = 0;
    int now = 0;
    while(deq.size()) {
        if(t == 0) {
            a += deq.front();
            now += deq.front();
            deq.pop_front();
            if(now > previous and deq.size()) t = 1, turns++, previous = now, now = 0;
        } else {
            b += deq.back();
            now += deq.back();
            deq.pop_back();
            if(now > previous and deq.size()) t = 0, turns++, previous = now, now = 0;
        }
    }
    cout << turns << " " << a << " " << b << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}