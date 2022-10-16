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
ll A[105000];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N, Q;
    cin >> N >> Q;
    ll one = 0;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        if(A[i] == 1) one++; 
    }
    for(int q = 0; q < Q; q++) {
        ll t, x;
        cin >> t >> x;
        if(t == 1) {
            x--;
            if(A[x] == 1) one--;
            A[x] = 1 - A[x];
            if(A[x] == 1) one++;
        } else {
            if(one >= x) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}