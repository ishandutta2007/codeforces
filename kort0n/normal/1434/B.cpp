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
ll N;
ll ans[205000];
char c[201000];
ll v[201000];
set<ll> st;
ll inv[201000];

bool valid() {
    set<ll> st;
    for(int i = 0; i < 2 * N; i++) {
        if(c[i] == '+') {
            st.insert(ans[i]);
        } else {
            auto itr = st.begin();
            if(*itr != v[i]) return false;
            itr = st.erase(itr);
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < 2 * N; i++) {
        cin >> c[i];
        if(c[i] == '-') {
            cin >> v[i];
            inv[v[i]] = i;
        } else st.insert(i);
    }
    for(int i = 1; i <= N; i++) {
        auto itr = st.lower_bound(inv[i]);
        if(itr == st.begin()) {
            cout << "NO" << endl;
            return 0;
        }
        itr--;
        ans[*itr] = i;
        itr = st.erase(itr);
    }
    if(valid()) {
        cout << "YES" << endl;
        for(int i = 0; i < 2 * N; i++) {
            if(ans[i] != 0) cout << ans[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}