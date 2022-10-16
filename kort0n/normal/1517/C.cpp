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
ll ans[505][505];
ll A[505];
ll dh[4] = {1, -1, 0, 0};
ll dw[4] = {0, 0, 1, -1};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        ans[i][i] = A[i];
    }
    for(int i = 0; i < N; i++) {
        set<l_l> st;
        st.insert({i, i});
        for(int t = 1; t <= A[i]; t++) {
            auto tmp = *st.begin();
            st.erase(st.begin());
            ll w = tmp.first;
            ll h = tmp.second;
            ans[h][w] = A[i];
            for(int k = 0; k < 4; k++) {
                int newh = h + dh[k];
                int neww = w + dw[k];
                if(newh < 0 or newh >= N or neww < 0 or neww >= N) continue;
                if(newh < neww) continue;
                if(ans[newh][neww] != 0) continue;
                st.insert({neww, newh});
            }
        }
    }
        for(int i = 0; i < N; i++) {
            for(int j = 0; j <= i; j++) {
                if(j != 0) cout << " ";
                cout << ans[i][j];
            }
            cout << endl;
        }
    return 0;
}