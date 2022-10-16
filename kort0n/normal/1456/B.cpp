#include <bits/stdc++.h>
//#include <atcoder/all>
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
ll a[105000];
ll SUM[105000];
ll ans = INF;
ll N;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    if(N >= 100) {
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        SUM[i+1] = SUM[i] ^ a[i];
    }
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
            for(ll k = j + 1; k <= N; k++) {
                if((SUM[j]^SUM[i]) > (SUM[j]^SUM[k])) {
                    chmin(ans, (j - i - 1) + (k - j - 1));
                }
            }
        }
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}