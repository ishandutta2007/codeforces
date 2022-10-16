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
int N;
int inv[100500];
int b[100050];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 1; i <= N; i++) {
        int a;
        cin >> a;
        inv[a] = i;
    }
    for(int i = 1; i <= N; i++) {
        cin >> b[i];
        b[i] = inv[b[i]];
    }
    int ans = 0;
    int minimum = 1e9;
    for(int i = N; i >= 1; i--) {
        if(b[i] > minimum) ans++;
        chmin(minimum, b[i]);
    }
    cout << ans << endl;
    return 0;
}