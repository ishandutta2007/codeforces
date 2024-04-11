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

#define EPS (1e-7)
#define PI (acos(-1))
const ll INF = 1000000007;
ll beki(ll a, ll b) {
    if(b == 0) return 1;
    ll ret = beki(a, b / 2);
    ret = ret * ret;
    chmin(ret, INF);
    if(b & 1) ret = ret * a;
    chmin(ret, INF);
    return ret;
}
ll N, I;
vector<ll> a;
ll num = 0;
int main() {
    cin >> N >> I;
    a.resize(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    a.push_back(-1);
    sort(a.begin(), a.end());
    ll K = I * 8 / N;
    ll k = beki(2, K);
    cerr << K << " " << k << endl;
    ll l = 1;
    ll ans = 0;
    ll r = 1;
    a.push_back(1e18);
    while(l < N + 1) {
        while(r <= N) {
            if(a[r] != a[r-1] && num == k) break;
            if(a[r] != a[r-1]) num++;
            r++;
        }
        chmax(ans, r - l);
        //cerr << l << " " << r << " " << num << endl;
        if(a[l] != a[l+1]) num--;
        l++;
    }
    cout << N - ans << endl;
    return 0;
}