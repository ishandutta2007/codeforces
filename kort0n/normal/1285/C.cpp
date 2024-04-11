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
ll X;
l_l ans;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> X;
    ans.first = 1;
    ans.second = X;
    for(ll i = 2; i * i <= X; i++) {
        if(X % i != 0) continue;
        ll j = X / i;
        if(i * j / __gcd(i, j) != X) continue;
        ans.first = i;
        ans.second = j;
    }
    cout << ans.first << " " << ans.second << endl;
    return 0;
}