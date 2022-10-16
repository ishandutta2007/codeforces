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
ll n, p;

int g(ll now) {
    if(now == 0) return 0;
    return (now & 1LL) + g(now >> 1);
}

bool f(ll timer) {
    ll now = n - timer * p;
    if(now < timer) return false;
    return timer >= g(now);
}


int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> p;
    for(int i = 1; i <= 1e7; i++) {
        if(f(i)) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}