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
ll AB[1020000];
ll sum[1020000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    for(ll i = A; i <= B; i++) {
        AB[i+B]++;
        AB[i+C+1]--;
    }
    for(int i = 0; i <= 1e6; i++) AB[i+1] += AB[i];
    ll ans = 0;
    for(int i = 1; i <= 1000005; i++) {
        sum[i] = sum[i-1] + AB[i-1];
    }
    for(int i = C; i <= D; i++) {
        ans += sum[1000005] - sum[i+1];
    }
    cout << ans << endl;
    return 0;
}