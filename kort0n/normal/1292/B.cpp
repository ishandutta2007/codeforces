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
ll x[60], y[60];
ll num = 1;
ll ax, ay, bx, by;
ll xs, ys, t;
ll ans = 0;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> x[0] >> y[0];
    cin >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    for(num = 1; ; num++) {
        if((1e18 - bx) / ax < x[num-1]) break;
        if((1e18 - by) / ay < y[num-1]) break;
        x[num] = ax * x[num-1] + bx;
        y[num] = ay * y[num-1] + by;
        //cerr << num << endl;
    }
    for(int i = 0; i < num; i++) {
        ll Rest = t - abs(xs - x[i]) - abs(ys - y[i]);
        if(Rest < 0) continue;
        //cerr << i << " " << x[i] << " " << y[i] << " " << Rest << endl;
        ll Time = Rest;
        ll j;
        for(j = i - 1; j >= 0; j--) {
            Time -= abs(x[j] - x[j+1]) + abs(y[j] - y[j+1]);
            if(Time < 0) break;
        }
        Time = Rest;
        chmax(ans, i - j);
        for(j = i + 1; j < num; j++) {
            Time -= abs(x[j] - x[j-1]) + abs(y[j] - y[j-1]);
            if(Time < 0) break;
        }
        chmax(ans, j - i);
    }
    cout << ans << endl;
    return 0;
}