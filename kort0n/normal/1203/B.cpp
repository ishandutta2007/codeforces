#include <bits/stdc++.h>
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

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;

void solve() {
    int N;
    cin >> N;
    vector<int> v(4 * N);
    for(int i = 0; i < 4 * N; i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<int> w;
    for(int i = 0; i < v.size(); i += 2) {
        if(v[i] != v[i+1]) {
            cout << "NO" << endl;
            return;
        }
        w.push_back(v[i]);
    }
    int val = w[0] * w.back();
    for(int i = 1; i < w.size(); i++) {
        if(w[i] * w[w.size() - 1 - i] != val) {
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