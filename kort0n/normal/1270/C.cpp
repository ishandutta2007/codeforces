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

int A[105000];

void solve() {
    int N;
    cin >> N;
    ll XOR = 0;
    ll sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        XOR ^= A[i];
        sum += A[i];
    }
    cout << 2 << "\n";
    cout << XOR << " " << sum + XOR << "\n";
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