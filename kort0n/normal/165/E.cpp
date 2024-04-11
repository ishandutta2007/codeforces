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

ll dp[1 << 24];
int bitmaxi = 24;
int ALL = (1<<24) - 1;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<int> a(N);
    for(int i = 0; i < (1 << bitmaxi); i++) {
        dp[i] = -1;
    }
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        dp[ALL ^ a[i]] = a[i];
    }
    for(int i = ALL - 1; i >= 0; i--) {
        for(int j = 0; j < bitmaxi; j++) {
            if((i & (1 << j))) continue;
            int from = i ^ (1 << j);
            if(dp[from] == -1) continue;
            dp[i] = dp[from];
        }
    }
    for(int i = 0; i < N; i++) {
        cout << dp[a[i]] << " ";
    }
    cout << endl;
    return 0;
}