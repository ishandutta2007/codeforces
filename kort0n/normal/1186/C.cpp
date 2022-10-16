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
    string a, b;
    cin >> a >> b;
    int ans = 0;
    int ret = 1e7;
    int parity = 0;
    for(int i = 0; i < b.size(); i++) {
        if(a[i] != b[i]) ret++;
    }
    for(int i = 1; i < b.size(); i++) {
        if(b[i-1] != b[i]) parity = 1 - parity;
    }
    if(ret % 2 == 0) ans++;
    for(int i = 1; i - 1 + b.size() < a.size(); i++) {
        if(a[i-1] != b[0]) ret++;
        if(a[i-1+b.size()] != b.back()) ret++;
        ret += parity;
        if(ret % 2 == 0) ans++;
    }
    cout << ans << endl;
    return 0;
}