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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    bool exist = false;
    for(auto val : a) {
        if(val == K) exist = true;
    }
    if(!exist) {
        cout << "no" << endl;
        return;
    }
    if(N == 1) {
        cout << "yes" << endl;
        return;
    }
    ll mini = 0;
    ll now = 0;
    bool LastMin = true;
    for(int i = 0; i < N; i++) {
        if(!LastMin and a[i] >= K) {
            cout << "yes" << endl;
            return;
        }
        if(a[i] >= K) now++;
        else now--;
        LastMin = chmin(mini, now);
    }
    cout << "no" << endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}