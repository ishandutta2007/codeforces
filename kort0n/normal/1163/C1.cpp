#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<l_l, l_l> l_l_l_l;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
ll gcd(ll a, ll b) {
    if(a < b) swap(a, b);
    if(b == 0) return a;
    if(a % b == 0) return b;
    return gcd(b, a % b);
}

set<l_l_l_l> st;

ll x[1005], y[1005];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j < i; j++) {
            ll dx = x[j] - x[i];
            ll dy = y[j] - y[i];
            if(dx < 0) {
                dx *= -1;
                dy *= -1;
            }
            if(dx == 0) dy = abs(dy);
            ll GCD = gcd(dx, abs(dy));
            dx /= GCD;
            dy /= GCD;
            l_l sub;
            if(dx != 0) {
                ll bunbo = dx;
                ll bunsi = y[i] * dx - x[i] * dy;
                if(bunbo < 0) {
                    bunbo *= -1;
                    bunsi *= -1;
                }
                GCD = gcd(abs(bunbo), abs(bunsi));
                bunbo /= GCD;
                bunsi /= GCD;
                sub = {bunsi, bunbo};
            } else {
                sub = {x[i], 0};
            }
            st.insert({{dx, dy}, sub});
        }
    }
    ll ans = 0;
    ll before = 0;
    ll now = 0;
    l_l nowm = {0, 0};
    while(!st.empty()) {
        auto itr = st.begin();
        l_l_l_l nowcheck = *itr;
        //cerr << nowcheck.first.first << " " << nowcheck.first.second << " " << nowcheck.second.first << " " << nowcheck.second.second << endl;
        st.erase(itr);
        if(nowcheck.first == nowm) {
            ans += before;
            now++;
        } else {
            before += now;
            ans += before;
            now = 1;
            nowm = nowcheck.first;
        }
    }
    cout << ans << endl;
    return 0;
}