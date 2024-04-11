#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    if(a == b) {
        cout << 0 << endl;
        return 0;
    }
    if(a < b) swap(a, b);
    ll delta = a - b;
    vector<ll> div;
    for(ll i = 1; i * i <= delta; i++) {
        if(delta % i != 0) continue;
        div.push_back(i);
        div.push_back(delta / i);
    }
    sort(div.begin(), div.end());
    ll ansval = 2e18;
    ll ans = -1;
    for(int i = 0; i < div.size(); i++) {
        ll now = div[i];
        ll nowans = now - b % now;
        nowans %= now;
        ll nowval = (nowans + b) * (nowans + a) / now;
        if(nowval >= ansval) continue;
        ansval = nowval;
        ans = nowans;
    }
    cout << ans << endl;
    return 0;
}