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
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

void solve() {
    ll N;
    cin >> N;
    vector<ll> v(N + 1);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
        v[i] /= 100;
    }
    v[0] = 1e10;
    sort(v.begin(), v.end(), greater<ll>());
    ll x, y, a, b;
    cin >> x >> a >> y >> b;
    if(x < y) {
        swap(x, y);
        swap(a, b);
    }
    ll k;
    cin >> k;
    vector<ll> sum(N + 1);
    for(int i = 1; i <= N; i++) {
        sum[i] = sum[i-1] + v[i];
    }
    ll xnum = 0;
    ll ynum = 0;
    ll xynum = 0;
    for(int i = 1; i <= N; i++) {
        if(i % a == 0 && i % b == 0) xynum++;
        else if(i % a == 0) xnum++;
        else if(i % b == 0) ynum++;
        ll now = 0;
        now += sum[xynum] * (x + y);
        now += (sum[xynum+xnum] - sum[xynum]) * x;
        now += (sum[xynum+xnum+ynum] - sum[xynum+xnum]) * y;
        if(now >= k) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll Q;
    cin >> Q;
    while(Q--) solve();
    return 0;
}