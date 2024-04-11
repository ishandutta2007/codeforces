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

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(2 * n);
    for(int i = 0; i < 2 * n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if(v[0] == v[2*n-1]) {
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < 2 * n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}