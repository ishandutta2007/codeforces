#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<char, int> c_i;
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
    string a, b;
    cin >> a >> b;
    vector<c_i> v, u;
    v.push_back({a[0], 1});
    u.push_back({b[0], 1});
    for(int i = 1; i < a.size(); i++) {
        if(a[i] == a[i-1]) {
            v.back().second++;
            continue;
        }
        v.push_back({a[i], 1});
    }
    for(int i = 1; i < b.size(); i++) {
        if(b[i] == b[i-1]) {
            u.back().second++;
            continue;
        }
        u.push_back({b[i], 1});
    }
    if(v.size() != u.size()) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < v.size(); i++) {
        if(v[i].first != u[i].first) {
            cout << "NO" << endl;
            return;
        }
        if(v[i].second > u[i].second) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}