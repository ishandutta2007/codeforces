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
int ans[1005][1005];

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    int val = 0;
    for(int i = 0; i < N; i += 2) {
        for(int j = 0; j < N; j += 2) {
            ans[i][j] = val;
            ans[i][j+1] = val + 1;
            ans[i+1][j] = val + 2;
            ans[i+1][j+1] = val + 3;
            val += 4;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < N; i++) {
        int now = 0;
        for(int j = 0; j < N; j++) now ^= ans[i][j];
        if(now != 0) cerr << i << endl;
    }
    for(int i = 0; i < N; i++) {
        int now = 0;
        for(int j = 0; j < N; j++) now ^= ans[j][i];
        if(now != 0) cerr << i << endl;
    }
    return 0;
}