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

void solve() {
    int n, k;
    cin >> n >> k;
    int maxi = 1e9;
    int mini = 0;
    while(n--) {
        int a;
        cin >> a;
        chmin(maxi, a + k);
        chmax(mini, a - k);
    }
    if(maxi < mini) maxi = -1;
    cout << maxi << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    while(q--) solve();
    return 0;
}