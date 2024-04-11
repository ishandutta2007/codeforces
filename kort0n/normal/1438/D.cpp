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
ll a[105000];
vector<vector<ll>> ans;

void f(int i, int j, int k) {
    assert(i != j and j != k and k != i);
    ll val = a[i] ^ a[j] ^ a[k];
    a[i] = val;
    a[j] = val;
    a[k] = val;
    ans.push_back({i, j, k});
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll N;
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int i = 1; i + 1 < N; i += 2) {
        f(0, i, i + 1);
    }
    for(int i = 1; i + 1 < N; i += 2) {
        f(0, i, i + 1);
    }
    for(int i = 0; i < N; i++) {
        if(a[i] != a[0]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(auto tmp : ans) {
        cout << tmp[0] + 1 << " " << tmp[1] + 1 << " " << tmp[2] + 1 << endl;
    }
    return 0;
}