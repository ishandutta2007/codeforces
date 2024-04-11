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
ll M[1005][1005];
ll a[1005];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) cin >> M[i][j];
    }
    a[1] = pow(M[1][2] * M[1][3] / M[2][3], 0.5);
    cout << a[1];
    for(int i = 2; i <= n; i++) {
        a[i] = M[1][i] / a[1];
        cout << " " << a[i];
    }
    cout << endl;
    return 0;
}