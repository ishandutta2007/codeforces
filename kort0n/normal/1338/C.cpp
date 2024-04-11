#include <bits/stdc++.h>
#define endl "\n"
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
ll b[3][4];
void solve() {
    ll N;
    cin >> N;
    /*
    if(N <= 3) {
        cout << N << endl;
        return;
    }
    */
    ll idx = (N - 1) % 3;
    //ll t = (N + 2) / 3;
    N = (N + 2) / 3;
    vector<ll> a(3);
    ll sum = 0;
    for(ll i = 0; ; i++) {
        sum = (1LL << (2 * i));
        if(sum >= N) {
            //cerr << "N: " << N << endl;
            for(int j = 0; j < 3; j++) {
                a[j] += b[j][1] << (2 * i);
            }
            for(ll j = i - 1; j >= 0; j--) {
                for(ll k = 0; k < 4; k++) {
                    if(1LL << (2 * j) < N) {
                        N -= 1LL << (2 * j);
                    } else {
                        //cerr << i << " " << j << " " << k << endl;
                        a[idx] += b[idx][k] << (2 * j);
                        break;
                    }
                }
            }
            cout << a[idx] << endl;
            return;
        } else {
            N -= sum;
        }
    }
    //cout << a[idx] << endl;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
int main() {
    b[0][0] = 0;
    b[0][1] = 1;
    b[0][2] = 2;
    b[0][3] = 3;
    b[1][0] = 0;
    b[1][1] = 2;
    b[1][2] = 3;
    b[1][3] = 1;
    b[2][0] = 0;
    b[2][1] = 3;
    b[2][2] = 1;
    b[2][3] = 2;
    ll T;
    cin >> T;
    while(T--) solve();
    return 0;
}