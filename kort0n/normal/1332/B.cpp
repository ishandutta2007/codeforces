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
void solve() {
    ll N;
    cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    set<ll> st;
    vector<ll> ans(N);
    for(int i = 0; i < N; i++) {
        for(ll j = 2; j <= 1000; j++) {
            if(a[i] % j == 0) {
                ans[i] = j;
                st.insert(j);
                break;
            }
        }
    }
    ll num = 0;
    for(int i = 0; i < N; i++) {
        auto itr = st.lower_bound(ans[i]);
        ans[i] = distance(st.begin(), itr) + 1;
        chmax(num, ans[i]);
    }
    cout << num << endl;
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}