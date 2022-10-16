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
ll a[201000];
ll ans = 0;

int main() {
    ll N;
    cin >> N;
    for(int i = 0; i < N;i++) {
        cin >> a[i];
    }
    ll idx = 0;
    while(idx != N) {
        set<ll> st;
        st.insert(0);
        ll sum = 0;
        while(idx != N) {
            sum += a[idx];
            if(st.find(sum) != st.end()) {
                ans++;
                break;
            }
            st.insert(sum);
            idx++;
        }
    }
    cout << ans << endl;
    return 0;
}