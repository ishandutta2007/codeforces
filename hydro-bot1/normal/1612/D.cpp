// Hydro submission #62625f749f31360077db4214@1650614133123
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int N = 100 + 10;
template<class T> const T INF = numeric_limits<T>::max() / 2 - 1;

ll ex(ll a, ll b, const ll & x) {
    if (a < b) swap(a, b);
    if (a == x || b == x) {
        return true;
    }
    if (a == 0 || b == 0) {
        return false;
    }
    if (x > a) {
        return false;
    }
    if (x % b == a % b) {
        return true;
    }
    return ex(a % b, b, x);
}

inline bool solve() {
    ll a, b, x;
    cin >> a >> b >> x;
    return ex(a, b, x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T --) {
        cout << (solve() ? "YES" : "NO") << endl;
    }
    return 0;
}
/*
*/