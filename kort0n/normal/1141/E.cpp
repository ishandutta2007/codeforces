#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll H, n;
ll d[200500];
ll delta;

ll check(ll times) {
    ll initial = H + delta * times;
    if(initial <= 0) return 0;
    for(ll i = 1; i <= n; i++) {
        initial += d[i];
        if(initial <= 0) return i;
    }
    return -1;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> H >> n;
    for(int i = 1; i <= n; i++) cin >> d[i];
    for(int i = 1; i <= n; i++) delta += d[i];
    if(delta >= 0) {
        if(check(0) >= 0) {
            cout << check(0) << endl;
            return 0;
        }
        cout << -1 << endl;
        return 0;
    }
    ll ok = (H / (-delta)) + 1;
    ll ng = -1;
    while(ok - ng > 1) {
        ll mid = (ok + ng) / 2;
        if(check(mid) != -1) ok = mid;
        else ng = mid;
    }
    cout << ok * n + check(ok) << endl;
    return 0;
}