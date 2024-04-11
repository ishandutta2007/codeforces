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
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N), b(M);
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < M; i++) cin >> b[i];
    set<int> st;
    ll ans = 0;
    int aidx = 0;
    for(int i = 0; i < M; i++) {
        if(st.find(b[i]) == st.end()) {
            ans += 2 * st.size();
            while(true) {
                if(a[aidx] != b[i]) {
                    st.insert(a[aidx]);
                    aidx++;
                    ans += 2;
                } else {
                    aidx++;
                    ans++;
                    break;
                }
            }
        } else {
            st.erase(b[i]);
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}