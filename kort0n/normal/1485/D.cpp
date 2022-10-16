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
ll l = 1;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, M;
    cin >> N >> M;
    for(ll i = 1; i <= 16; i++) {
        l = l * i / __gcd(l, i);
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(j != 0) cout << " ";
            ll a;
            cin >> a;
            if((i + j) % 2 == 0) {
                cout << l;
            } else {
                cout << l - a*a*a*a;
            }
        }
        cout << endl;
    }
    return 0;
}