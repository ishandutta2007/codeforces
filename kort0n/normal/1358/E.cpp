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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    vector<ll> a(N);
    int n = (N + 1) / 2;
    for(int i = 0; i < n; i++) cin >> a[i];
    ll x;
    cin >> x;
    for(int i = n; i < N; i++) a[i] = x;
    vector<ll> sum(N + 1);
    for(int i = 0; i < N; i++) {
        sum[i+1] = sum[i] + a[i];
    }
    if(sum[N] > 0) {
        cout << N << endl;
        return 0;
    }
    ll nowd = 0;
    ll mind = 0;
    for(int k = N - 1; 2 * k > N; k--) {
        nowd += x - a[N-1-k];
        chmin(mind, nowd);
        ll initial = sum[k];
        if(initial + mind > 0) {
            cout << k << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}