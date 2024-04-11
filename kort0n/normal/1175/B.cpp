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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll ans = 0;
    bool OVER = false;
    ll l;
    cin >> l;
    stack<ll> sta;
    ll product = 1;
    while(l--) {
        //cerr << l << endl;
        string S;
        cin >> S;
        if(S == "add") {
            if(!sta.empty() && sta.top() == -1) OVER = true;
            ans += product;
            if(ans >= ((ll)1 << 32)) OVER = true;
            continue;
        }
        if(S == "end") {
            if(sta.top() != -1) product /= sta.top();
            sta.pop();
            continue;
        }
        ll x;
        cin >> x;
        if(product > ((ll)1 << 32)) {
            x = -1;
        } else {product *= x;}
        sta.push(x);
    }
    if(OVER) {
        cout << "OVERFLOW!!!" << endl;
        return 0;
    } else cout << ans << endl;
    return 0;
}