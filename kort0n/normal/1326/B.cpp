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
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    vector<ll> b(N);
    for(int i = 0; i < N; i++) cin >> b[i];
    ll x = 0;
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << x + b[i];
        ll a = x + b[i];
        chmax(x, a);
    }
    cout << endl;
    return 0;
}