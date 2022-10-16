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
    vector<ll> a(N + 1);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    stack<ll> sta;
    for(int i = 0; i < N; i++) {
        if(sta.empty() or sta.top() > a[i]) {
            sta.push(a[i]);
        } else {
            while(sta.size() > 1 and sta.top() < a[i]) {
                sta.pop();
            }
            if(sta.top() > a[i]) {
                sta.push(a[i]);
            }
        }
    }
    if(sta.size() == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}