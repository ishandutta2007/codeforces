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
ll n[3];
vector<ll> A[3];
ll sum[3];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 3; i++) {
        cin >> n[i];
    }
    for(int i = 0; i < 3; i++) {
        A[i].resize(n[i]);
        for(int j = 0; j < n[i]; j++) {
            cin >> A[i][j];
            sum[i] += A[i][j];
        }
        sort(A[i].begin(), A[i].end());
    }
    ll mini = INF;
    for(int i = 0; i < 3; i++) {
        chmin(mini, sum[i]);
        for(int j = 0; j < i; j++) {
            chmin(mini, A[i][0] + A[j][0]);
        }
    }
    ll ans = sum[0] + sum[1] + sum[2] - 2 * mini;
    cout << ans << endl;
    return 0;
}