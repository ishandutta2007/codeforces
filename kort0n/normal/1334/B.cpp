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
    ll N, x;
    cin >> N >> x;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        sum += a[i];
        if(sum < x * (i + 1)) {
            cout << i << endl;
            return;
        }
    }
    cout << N << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}