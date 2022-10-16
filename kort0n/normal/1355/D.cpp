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
    ll N, S;
    cin >> N >> S;
    if(S < 2 * N) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << S - 2 * (N - 1);
    for(int i = 1; i < N; i++) {
        cout << " "<< 2;
    }
    cout << endl;
    cout << 1 << endl;
    return 0;
}