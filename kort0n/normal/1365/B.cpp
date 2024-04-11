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
    set<int> st;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 0; i < N; i++) {
        int b;
        cin >> b;
        st.insert(b);
    }
    if(st.size() == 2) {
        cout << "Yes" << endl;
        return;
    }
    for(int i = 1; i < N; i++) {
        if(a[i-1] > a[i]) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}