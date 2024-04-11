#include <bits/stdc++.h>
#define endl "\n"
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

const long long INF = 1e18;
//const ll mod = 1000000007;
ll a[2][3];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll K;
    cin >> K;
    ll inf = 1;
    while(inf * 2 <= 3e5) inf *= 2;
    inf--;
    a[0][0] = inf;
    a[1][1] = inf;
    a[1][2] = K;
    a[0][1] = K;
    a[1][0] = (inf + 1) / 2;
    cout << 2 << " " << 3 << endl;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            if(j != 0) cout << " ";
            cout << a[i][j];
        }
        cout << endl;
    }
    return 0;
}