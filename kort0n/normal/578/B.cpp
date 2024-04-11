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
ll N, k, x;
ll ans = 0;
ll a[200050];
ll before[200050];
ll after[200050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> k >> x;
    for(int i = 1; i <= N; i++) cin >> a[i];
    for(int i = 1; i <= N; i++) before[i] = before[i-1] | a[i];
    for(int i = N; i >= 1; i--) after[i] = after[i+1] | a[i];
    for(int i = 1; i <= N; i++) {
        ll now = a[i];
        ll others = before[i-1] | after[i+1];
        chmax(ans, now | others);
        for(int j = 1; j <= k; j++) {
            now *= x;
            chmax(ans, now | others);
        }
    }
    cout << ans << endl;
    return 0;
}