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
int N;
int a[105000];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> a[i];
    for(int bits = 30; bits >= 0; bits--) {
        int idx = -1;
        bool ok = true;
        for(int i = 0; i < N; i++) {
            if(a[i] & (1 << bits)) {
                if(idx == -1) idx = i;
                else ok = false;
            }
        }
        if(!ok) continue;
        if(idx == -1) continue;
        cout << a[idx];
        for(int i = 0; i < N; i++) {
            if(i == idx) continue;
            cout << " " << a[i];
        }
        cout << endl;
        return 0;
    }
    for(int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}