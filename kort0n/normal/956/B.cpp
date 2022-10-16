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
int N, U;

int main() {
    cin >> N >> U;
    vector<int> E(N + 1);
    for(int i = 0; i < N; i++) {
        cin >> E[i];
    }
    E[N] = 2e9;
    double ans = -1;
    for(int i = 0; i < N; i++) {
        auto itr = upper_bound(E.begin(), E.end(), E[i] + U);
        itr--;
        int idx = distance(E.begin(), itr);
        if(idx <= i + 1) continue;
        int a = E[idx] - E[i+1];
        int b = E[idx] - E[i];
        chmax(ans, (double)a / b);
    }
    if(ans < -0.5) cout << -1 << endl;
    else cout << fixed << setprecision(30) << ans << endl;
    return 0;
}