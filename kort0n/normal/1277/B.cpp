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
    int N;
    cin >> N;
    map<int, int> mp;
    int ans = 0;
    while(N--) {
        int a;
        cin >> a;
        int d = 0;
        while(a % 2 == 0) {
            a /= 2;
            d++;
        }
        chmax(mp[a], d);
    }
    for(auto val : mp) {
        ans += val.second;
    }
    cout << ans << "\n";
}

int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}