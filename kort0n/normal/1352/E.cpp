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
    int N;
    cin >> N;
    vector<int> a(N);
    vector<int> sum(N + 1);
    multiset<int> st;
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
        st.insert(a[i]);
    }
    for(int i = 0; i <= N; i++) {
        for(int j = i + 2; j <= N; j++) {
            st.erase(sum[j] - sum[i]);
        }
    }
    cout << N - st.size() << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}