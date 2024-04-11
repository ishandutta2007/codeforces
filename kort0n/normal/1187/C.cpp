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
bool great[1005];
int t[1005], l[1005], r[1005];
int a[1005];
int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        cin >> t[i] >> l[i] >> r[i];
        if(t[i] == 1) {
            for(int j = l[i] + 1; j <= r[i]; j++) great[j] = true;
        }
    }
    a[1] = 5e5;
    for(int j = 2; j <= n; j++) {
        if(great[j]) a[j] = a[j-1] + 1;
        else a[j] = a[j-1] - 1;
    }
    for(int i = 1; i <= m; i++) {
        if(t[i]) continue;
        bool clear = false;
        for(int j = l[i] + 1; j <= r[i]; j++) {
            if(a[j-1] > a[j]) {
                clear = true;
            }
        }
        if(!clear) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}