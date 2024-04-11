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
    int N;
    int a[205000];
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> a[i];
    int mindex = 1;
    for(int i = 1; i <= N; i++) {
        if(a[mindex] < a[i]) mindex = i;
    }
    cerr << mindex << endl;
    for(int i = mindex + 1; i <= N; i++) {
        if(a[i] > a[i-1]) {
            cerr << i << endl;
            cout << "NO" << endl;
            return 0;
        }
    }
    for(int i = mindex - 1; i >= 1; i--) {
        if(a[i] > a[i+1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}