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
ll N;
ll a[105000];
ll num[105000];
bool f(ll border) {
    for(int i = 0; i < N; i++) num[i] = 0;
    for(int i = 0; i < N; i++) num[a[i]]++;
    priority_queue<l_l> que;
    for(int i = 0; i < N; i++) {
        if(num[i]) que.push({num[i], i});
    }
    vector<ll> v(N);
    for(int day = 0; day < N; day++) {
        if(day >= border + 1) {
            ll tmp = v[day - border - 1];
            if(num[tmp]) que.push({num[tmp], tmp});
        }
        if(que.empty()) return false;
        auto tmp = que.top();
        que.pop();
        v[day] = tmp.second;
        num[tmp.second]--;
    }
    return true;
}

void solve() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    ll ok = 0;
    ll ng = N;
    while(abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if(f(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}