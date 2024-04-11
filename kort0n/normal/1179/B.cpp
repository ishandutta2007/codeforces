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
int n, m;

void f(int u, int d) {
    for(int i = 1; i <= m; i++) {
        cout << u << " " << i << "\n";
        cout << d << " " << m + 1 - i << "\n";
    }
}

void g(int u) {
    for(int i = 1; i * 2 <= m; i++) {
        cout << u << " " << i << "\n";
        cout << u << " " << m + 1 - i << "\n";
    }
    if(m % 2 == 1) {
        cout << u << " " << (m + 1) / 2 << "\n";
    }
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i * 2 <= n; i++) {
        f(i, n + 1 - i);
    }
    if(n % 2 == 1) {
        g((n + 1) / 2);
    }
    return 0;
}