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
int before[200500];
void solve() {
    int N;
    cin >> N;
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int ans = 1e9;
    for(int i = 1; i <= N; i++) {
        before[i] = -1;
    }
    for(int i = 0; i < N; i++) {
        if(before[v[i]] != -1) {
            chmin(ans, i - before[v[i]] + 1);
        }
        before[v[i]] = i;
    }
    if(ans == INF) ans = -1;
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}