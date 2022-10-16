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
    ll N;
    cin >> N;
    set<l_l> st;
    for(int i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        if(a == 0) continue;
        ll g = __gcd(abs(a), abs(b));
        a /= g;
        b /= g;
        if(a < 0) {
            a *= -1;
            b *= -1;
        }
        st.insert({a, b});
    }
    cout << st.size() << endl;
    return 0;
}