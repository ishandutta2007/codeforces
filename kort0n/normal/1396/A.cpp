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
ll N;
ll a[105000];
int main() {
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    a[0] = 0;
    if(N >= 2) {
        cout << 2 << " " << N << endl;
        for(int i = 1; i < N; i++) {
            ll tmp = (a[i] + N * 10000000000) % N;
            tmp *= N - 1;
            cout << tmp << " ";
            a[i] += tmp;
        }
        cout << endl;
    } else {
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        a[0] = 0;
    }
    cout << 1 << " " << N << endl;
    for(int i = 0; i < N; i++) {
        assert(a[i] % N == 0);
        cout << -a[i] << " ";
    }
    cout << endl;
    return 0;
}