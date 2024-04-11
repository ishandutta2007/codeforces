#include <bits/stdc++.h>
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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

ll g(ll x) {
    if(x & 1) return 0;
    else return g(x/2) + 1;
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(31);
    vector<ll> sum(32);
    for(int i = 0; i < M; i++) {
        ll b;
        cin >> b;
        a[g(b)]++;
    }
    for(int i = 1; i <= 31; i++) {
        sum[i] = sum[i-1] + a[i-1] * (1LL << (i-1));
    }
    if(sum[31] < N) {
        cout << -1 << endl;
        return;
    }
    ll ans = 0;
    for(int idx = 30; idx >= 0; idx--) {
        //cerr << idx << " " << N << endl;
        while((a[idx] > 0) and ((1LL << idx) <= N)) {
            N -= (1LL << idx);
            a[idx]--;
        }
        if(a[idx] > 0 and sum[idx] < N) {
            a[idx]--;
            a[idx-1] += 2;
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}