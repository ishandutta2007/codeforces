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
    int a[2] = {0, 0};
    vector<int> v(N);
    for(int i = 0; i < N; i++) {
        cin >> v[i];
        a[v[i]&1]++;
    }
    string ans = "No";
    if(a[0] % 2 == 0) ans = "Yes";
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(v[i] % 2 != v[j] % 2) {
                if(abs(v[i] - v[j]) <= 1) ans = "Yes";
            }
        }
    }
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}