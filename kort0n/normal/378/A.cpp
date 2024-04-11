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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    int ans[3] = {0, 0, 0};
    for(int i = 1; i <= 6; i++) {
        int d = abs(a - i);
        int e = abs(b - i);
        if(d < e) ans[0]++;
        if(d == e) ans[1]++;
        if(d > e) ans[2]++;
    }
    cout << ans[0] << " " << ans[1] << " " << ans[2] << endl;
    return 0;
}