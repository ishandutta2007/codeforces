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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M, p;
    cin >> N >> M >> p;
    vector<ll> a(N), b(M);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];
    ll aidx, bidx;
    for(int i = 0; i < N; i++) {
        if(a[i] % p != 0) {
            aidx = i;
            break;
        }
    }
    for(int i = 0; i < M; i++) {
        if(b[i] % p != 0) {
            bidx = i;
            break;
        }
    }
    cout << aidx + bidx << endl;
    return 0;
}