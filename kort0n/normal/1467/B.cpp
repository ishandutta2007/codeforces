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
ll A[301000];
ll B[301000];
ll base;
ll ans;

void solve() {
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i <= N; i++) B[i] = 0;
    base = 0;
    for(int i = 1; i + 1 < N; i++) {
        if(A[i] < A[i+1] and A[i] < A[i-1]) B[i] = 1;
        if(A[i] > A[i+1] and A[i] > A[i-1]) B[i] = 1;
        base += B[i];
    }
    ans = base;
    for(int i = 1; i + 1 < N; i++) {
        ll val = A[i];
        for(int j = -1; j <= 1; j += 2) {
            ll tmp = base;
            A[i] = A[i+j];
            for(int k = i - 1; k <= i + 1; k++) {
                if(k == 0) continue;
                if(k == N - 1) continue;
                tmp -= B[k];
                if(A[k] < A[k+1] and A[k] < A[k-1]) tmp++;
                if(A[k] > A[k+1] and A[k] > A[k-1]) tmp++;
            }
            chmin(ans, tmp);
        }
        A[i] = val;
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}