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
    int mask = (1 << 7) - 1;
    cout << "?";
    for(int i = 1; i <= 100; i++) {
        cout << " " << i * (1 << 7);
    }
    cout << endl;
    int a;
    cin >> a;
    a &= mask;
    cout << "?";
    for(int i = 1; i <= 100; i++) {
        cout << " " << i;
    }
    cout << endl;
    int b;
    cin >> b;
    b &= ~mask;
    cout << "! " << a + b << endl;
    return 0;
}