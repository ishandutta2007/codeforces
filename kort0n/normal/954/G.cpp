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
vector<ll> b, a;
ll N, R, K;

bool f(ll border) {
    vector<ll> Add(N + 1);
    ll k = K;
    for(int i = 0; i < N; i++) {
        if(i) Add[i] += Add[i-1];
        ll delta = border - Add[i] - a[i];
        if(delta > 0) {
            k -= delta;
            ll idx = i + 2 * R + 1;
            if(idx <= N) Add[idx] -= delta;
            Add[i] += delta;
        }
        if(k < 0) return false;
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> R >> K;
    a.resize(N);
    b.resize(N);
    for(int i = 0; i < N; i++) {
        cin >> b[i];
        ll idx = i - R;
        chmax(idx, 0LL);
        a[idx] += b[i];
        idx = i + R + 1;
        if(idx < N) a[idx] -= b[i];
    }
    for(int i = 1; i < N; i++) {
        a[i] += a[i-1];
    }
    ll ok = 0;
    ll ng = 2e18;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}