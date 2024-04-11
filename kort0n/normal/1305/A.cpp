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

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);
//const ll mod = 1000000007;
vector<ll> x, y;

void solve() {
    ll N;
    cin >> N;
    x.resize(N);
    y.resize(N);
    for(int i = 0; i < N; i++) cin >> x[i];
    for(int i = 0; i < N; i++) cin >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << x[i];
    }
    cout << endl;
    for(int i = 0; i < N; i++) {
        if(i != 0) cout << " ";
        cout << y[i];
    }
    cout << endl;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}