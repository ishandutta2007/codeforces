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

void solve() {
    ll n;
    cin >> n;
    set<ll> st;
    for(int i = 1; i <= n; i++) {
        ll in;
        cin >> in;
        st.insert(in);
    }
    ll ans = 0;
    for(auto itr = st.begin(); itr != st.end(); itr++) {
        chmax(ans, *itr);
        auto itr2 = st.end();
        itr2--;
        while(itr2 != itr) {
            if(*itr2 % *itr != 0) break;
            itr2--;
        }
        if(itr == itr2) continue;
        chmax(ans, *itr + *itr2);
        auto itr3 = itr2;
        itr3--;
        while(itr3 != itr) {
            if(*itr3 % *itr != 0 && *itr2 % *itr3 != 0) break;
            itr3--;
        }
        if(itr3 == itr) continue;
        chmax(ans, *itr + *itr2 + *itr3);
    }
    cout << ans << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll q;
    cin >> q;
    while(q--) solve();
    return 0;
}