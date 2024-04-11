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
int a[500500];
int ans[805][805];
 
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1) {
            a[x] += y;
            for(int i = 1; i <= 600; i++) {
                ans[i][x % i] += y;
            }
            continue;
        } else if(t == 2) {
            if(x <= 600) {
                cout << ans[x][y] << "\n";
                continue;
            } else {
                int now = 0;
                for(ll i = y; i <= 500000; i += x) {
                    now += a[i];
                }
                cout << now << "\n";
                continue;
            }
        }
    }
    return 0;
}