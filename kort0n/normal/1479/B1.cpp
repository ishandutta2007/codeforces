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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    set<ll> st;
    ll must = -1;
    st.insert(-1);
    ll ans = 0;
    for(int i = 0; i < N; i++) {
        /*
        cerr << "--------" << i << "-------" << endl;
        cerr << must << endl;
        for(auto val : st) cerr << val << " ";
        cerr << endl;
        */
        ll tmp;
        cin >> tmp;
        if(must == tmp) {
            if(st.size() - st.count(tmp) != 0) {
                st.clear();
                ans++;
                st.insert(must);
            }
        } else {
            ans++;
            if(st.size() - st.count(tmp) != 0) {
                st.insert(must);
            }
            must = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}