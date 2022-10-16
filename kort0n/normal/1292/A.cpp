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
bool lava[2][105000];
int N, Q;
int Out = 0;

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for(int q = 1; q <= Q; q++) {
        int r, c;
        cin >> r >> c;
        r--;
        for(int i = c - 1; i <= c + 1; i++) {
            if(lava[1-r][i] && lava[r][c]) Out--;
        }
        lava[r][c] ^= true;
        for(int i = c - 1; i <= c + 1; i++) {
            if(lava[1-r][i] && lava[r][c]) Out++;
        }
        if(Out >= 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}